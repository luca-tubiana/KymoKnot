#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define  _GNU_SOURCE
#include <getopt.h>
#include <unistd.h>
#include <time.h>
#include "KNT_defaults.h"
#include "KNT_arc.h"
#include "KNT_lib.h"
#include "KNT_closures.h"
#include "KNT_io.h"
#include "KNT_qhull.h"
#include "my_random.h"
#include "libgen.h"

#define _VERSION_ "1.0"

#define BU  0
#define TD  1
#define UNS 2
#define N_SEARCHES 3
#define MEMLEN 1000
#define QH_B_SIZE  16000

void print_help();

int main(int argc,char** argv)
{
  int i;            /*usual loop index */
	int l;
  int c;
  int cnt;
  int start, end;
	int st_p=DONT_CARE;
	int end_p=DONT_CARE;
  int memlen = MEMLEN;
  int k_id;         /* knot identifier. Its values are defined in KNT_defaults.h */
  char cls_type = QHULLCLOSUREHYB[0]; /* kind of closure to be performed */
  FILE * fp_in_data;
  char filename[1024];
	char *bname;
  char fout_name   [N_SEARCHES][1024];
  char arc_id      [N_SEARCHES] = {ARC_ID_SK,ARC_ID_SCK,ARC_ID_SKU};
  char fout_expl   [N_SEARCHES][256]= {"shortest knotted portion: bottom-up scheme","shortest continuosly-knotted portion: Top-down scheme","shortest knotted portion, no check on complementar arc"};
  char fout_prefix [N_SEARCHES][16] = {"BU_","TD_","UNS_"};
  char line        [N_SEARCHES][128];
  int  S_flag      [N_SEARCHES] = {0,0,0};
  FILE * fout      [N_SEARCHES];
  int flag_debug=0;
  KNTarc * knt_rect;
  KNTarc * knt_ptr;
  KNTarc * knt_here;
  ALX_wspace * alx_wspace; /*memory workspace reserved for Alexander det computation */
  extern double ** COORD_BUFFER;

  int max_stride =  0; //default behaviour: no simplification
  int min_stride  = 2;
  int simp_sweeps = 4;

  int seed = time(NULL)+getpid(); //may be overkilling...


  if(argc < 2) { print_help(); }
  /*---GETOPT--------------------------------------------*/
  while ((c = getopt (argc, argv, "hbutdc:s:m:r:a:w:")) != -1)
  switch (c)
  {
    case 'h':
      print_help();
      break;
		case 'a':
			st_p=atoi(optarg);
			break;
		case 'w':
			end_p=atoi(optarg);
			break;
    case 's':
      max_stride = atoi(optarg);
      min_stride = (int)floor( max_stride/pow(2,simp_sweeps));
      min_stride = (min_stride > 3) ? min_stride : 2 ;
      fprintf(stderr,"simplification with min_stride %d -- max_stride %d\n",min_stride,max_stride);
      break;
    case 'b':
      S_flag[BU] = 1;
      break;
    case 't':
      S_flag[TD] = 1;
      break;
    case 'u':
      S_flag[UNS] = 1;
      break;
    case 'm':
      memlen = atoi ( optarg );
      fprintf(stderr,"Warning: Memory will be allocated to store %d beads.\n",memlen);
      fprintf(stderr,"Segmentation faults may result if the memory is not sufficient\n");
      break;
    case 'd':
      flag_debug=1;
      break;
    case 'c':
      if (strcmp(optarg,QHULLCLOSUREHYB) == 0)
      {
        cls_type = 'H';
        fprintf(stdout,"closure type: %s\n",QHULLCLOSUREHYB);
      }
      else if (strcmp(optarg,QHULLCLOSURE) == 0)
      {
        cls_type = 'Q';
        fprintf(stdout,"closure type: %s\n",QHULLCLOSURE);
      }
      else if (strcmp(optarg,BRIDGECLOSURE) == 0)
      {
        cls_type = 'B';
        fprintf(stdout,"closure type: %s\n",BRIDGECLOSURE);
      }
      /*
      else if (strcmp(optarg,RADIALCLOSURE) == 0)
        cls_type = 'R';
      else if (strcmp(optarg,STCHCLOSURE) == 0)
      {
        cls_type = 'S';
        flag_stch = 1;
        fprintf(stdout,"closure type: %s\n",STCHCLOSURE);
      }
      */
      else
        failed("closure type not recognized");
      failed("Not implemented yet..sorry\n");
      break;
    case 'r':
      seed = atoi(optarg);
      break;
    case '?':
      if (optopt == 'c')
        fprintf (stderr,
            "Option -%c requires an argument.\n",
            optopt);
      else if (isprint (optopt))
        fprintf (stderr,
            "Unknown option `-%c'.\n",
            optopt);
      else
        fprintf (stderr,
                 "Unknown option character `\\x%x'.\n",
                 optopt);
      return 1;
    default:
      abort ();
  }
  if (max_stride >= 0)
    fprintf(stderr,
        " simplification stride: %d\n Closure type:  %c\n",
        max_stride,cls_type);
  else
    fprintf(stderr,
        " simplification stride: unlimited\n Closure type: %c\n",
        cls_type);
  sprintf(filename,"%s",argv[argc-1]);
  if ((fp_in_data=fopen(filename,"r"))==NULL)
  {
    printf("Could not open file %s .\n",argv[1]);
    exit(1);
  }
  //Set up default behavior
  if ( S_flag[BU] == 0 && S_flag[TD] == 0 && S_flag[UNS] == 0 )
  {
    S_flag[BU] = S_flag[TD] = 1;
  }
  //Open files for output, print explanation
  fprintf(stderr,"Initializing PRNG with seed %d\n",seed);
  fprintf(stderr,"Performing the following knot_searches:\n");
  for ( i = 0 ; i < N_SEARCHES; i++)
  {
    if (S_flag[i])
    {
      fprintf(stderr,"%s\n",fout_expl[i]);
      fprintf(stderr,"file prefix: %s \n\n",fout_prefix[i]);
			bname=basename(filename);
      sprintf(fout_name[i],"%s_%s",fout_prefix[i],bname);
      if ((fout[i] = fopen(fout_name[i],"w"))==NULL)
      {
        printf("Could not open file %s .\n",fout_name[i]);
        exit(1);
      }
      fprintf(fout[i],"#%s\n",fout_expl[i]);
      fprintf(fout[i],"# index Adet_1 Adet_2\t start end length\n");
    }
  }

  cnt = 0;
  initialize_prng ( seed );
  /*allocate Alexander working space*/
  alx_wspace = ALX_wspace_alloc ( 2*memlen ); // This can be a limitation..
  /*read one ring at a time from input file. Main loop */
	while(( knt_ptr = KNTIOread_ring( fp_in_data)) != NULL )
	{
  	/*allocate qhull working space*/
		qhull_init(3*knt_ptr->len);
		buffer_init (&COORD_BUFFER,knt_ptr->len +MAX_CLS_POINTS);
		knt_rect = KNTLrectify_coord_local ( knt_ptr,0,knt_ptr->len, min_stride,max_stride );
		if (flag_debug)
		{
			fprintf(stderr,"--------------\n");
			KNTIOprint_ring(stderr,knt_rect);
			fprintf(stderr,"--------------\n");
			fflush(stderr);
		}
		KNTLrotate_random(knt_rect);
		fprintf(stderr,"knt_ptr->len %d -- knt_rect->len %d\n",knt_ptr->len, knt_rect->len);
		/*add space to save knot matrix */
		KNTadd_matrix(knt_rect);
		/*compute knot type of whole ring */
		k_id = KNTLknot_determination (  knt_rect,  alx_wspace );
		/*WARNING:**********************************************************************
		 * the preceding functions appends a knot_matrix to the KNTarc struct
		 * they receive as input. This is needed to save already computed entries
		 * and avoid redundant calculations during the search for the knotted portion(s).
		 * THE KNOT SEARCH FUNCTIONS MUST BE COMPUTED USING THE SAME CLOSURE SCHEME.
		 *******************************************************************************/
		/*int j;
		int rel_or, sep, r_sep;
		int d_s,d_e,n,I,J;
		int min_d_s=knt_ptr->len;
		int min_d_e=knt_ptr->len;
		if ((st_p != DONT_CARE || end_p !=DONT_CARE) && max_stride>0)
		{
			if ( st_p ==DONT_CARE) { st_p=0;}
			if ( end_p ==DONT_CARE) {end_p=knt_ptr->len;}
			I=-2;
			J=-2;
			rel_or=end_p-st_p;
			r_sep=(end_p>=st_p)?end_p-st_p:end_p-st_p+knt_ptr->len;
			for(i=0,j=knt_rect->len-1;i<knt_rect->len;i++,j--)
			{
				l = knt_rect->index[i];
				n = knt_rect->index[j];
				d_s= (st_p >= l)? st_p-l: l-st_p;
				d_e= (n >= end_p)? n-end_p: end_p-n;
				sep= (n>=l)? n-l: n-l+knt_ptr->len;
				if( d_s<min_d_s)
				{
					min_d_s=d_s;
					I=i;
				}
				if(d_e<min_d_e)
				{
					min_d_e=d_e;
					J=j;
				}
				if((J-I)*rel_or>0 && sep>r_sep-max_stride)
				{
					st_p=I;
					end_p=J;
				}
			}
			if (st_p==end_p)
			{
				st_p=DONT_CARE;
				end_p=DONT_CARE;
			}
		}
		else
		{
			st_p=end_p=DONT_CARE;
		}
		*/
		//--Begin the search
		for (i = 0 ; i< N_SEARCHES ; i++ )
		{
			if ( S_flag[i] )
			{
				sprintf(line[i],"RING %d\t %d %d\t",cnt,knt_rect->Adet_1,knt_rect->Adet_2 );
			}
		}
		st_p=DONT_CARE;
		end_p=DONT_CARE;
		if ( k_id != K_Un )
		{
			if (S_flag[BU] )
			{
				KNTLloc_shrt_knot_rect2    ( knt_ptr, knt_rect,st_p,end_p, KNTCqhull_hybrid_close_subchain, alx_wspace);
			}
			if ( S_flag[TD] )
			{
				KNTLloc_shrtcnt_knot_rect2 ( knt_ptr, knt_rect,st_p,end_p, KNTCqhull_hybrid_close_subchain, alx_wspace);
			}
			if ( S_flag[UNS] )
			{
				KNTLloc_shrt_knot_unsafe_rect2    ( knt_ptr, knt_rect,st_p,end_p, KNTCqhull_hybrid_close_subchain, alx_wspace);
			}
			//knt_here = knt_ptr;
			knt_here = knt_rect;
			do
			{
				for(i=0;i<N_SEARCHES;i++)
				{
					if(knt_here->arc_type == arc_id[i])
					{
						start = knt_rect->index[knt_here->start];
						end   = knt_rect->index[knt_here->end];
						//start = knt_here->start;
						//end   = knt_here->end;
						sprintf(line[i],"%s %d %d %d \t",
								line[i], start,end,(end > start)? end - start: end-start+ knt_ptr->len);
						if (flag_debug)
						{
							fprintf(stderr,"--------------\n");
							KNTIOprint_arc(stderr,knt_ptr,start,end);
							fprintf(stderr,"--------------\n");
						}
					}
				}
				knt_here = knt_here->next;
			}while( knt_here != NULL );
		}

		for ( i = 0; i < N_SEARCHES;i++ )
		{
			if ( S_flag[i] )
			{
				fprintf (fout[i],"%s\n",line[i] );
			}
		}
		KNTfree_arc ( knt_ptr );
		KNTfree_arc ( knt_rect );
		cnt++;
		free_buffer ( &COORD_BUFFER );
		qhull_terminate();
	}

  /* free memory */
  ALX_free_wspace(alx_wspace);

  /* close files */
  fclose(fp_in_data);
  for ( i = 0 ; i < N_SEARCHES ; i++ )
  {
    if ( S_flag[i] )
    {
      fclose (fout[i]);
    }
  }

  return 0;
}

void print_help()
{
  fprintf(stderr," \n");
  fprintf(stderr,"%s %s version %s\n\nLocates knotted portion on a ring\n",__DATE__,__FILE__,_VERSION_);
  fprintf(stderr,"The program identifies the knotted portion on ring chains  according to different search schemes [1].\n");
  fprintf(stderr,"Different search schemes identify different entanglement properties of a chain and may in general give different results.\n");
  fprintf(stderr,"For a detailed study, see ref [2].\n");
  fprintf(stderr,"In the current version, the bottom-up, top-down and  'unsafe' bottom-up search schemes can be used. The first two are enabled by\n");
  fprintf(stderr,"default if no search scheme is specified by the user.\n");
  fprintf(stderr,"\n[1] Tubiana L., Orlandini E, Micheletti C\n");
  fprintf(stderr,"Probing the Entanglement and Locating Knots in Ring Polymers: A Comparative Study of Different Arc Closure Schemes\n");
  fprintf(stderr,"Progress of Theoretical Physics supplement, 192, 192-204 (2011)\nhttp://ptp.ipap.jp/link?PTPS/191/192\n");
  fprintf(stderr,"\n[2] Tubiana L., Orlandini E, Micheletti C\n");
  fprintf(stderr,"Multiscale entanglement in ring polymers under spherical confinement\n");
  fprintf(stderr,"Phys. Rev. Lett. 107, pg 188302 (2011).\nhttp://prl.aps.org/pdf/PRL/v107/i18/e188302\n");
  fprintf(stderr,"-------------------------------------------------------\n");
  fprintf(stderr,"usage: KNTloc_linear.x [options] input_file\n");
  fprintf(stderr,"input file must be in the format:\n\tN\n\tx y z\n\tx y z\n\t...\n");
  fprintf(stderr,"where N is the length of the coordinate sets.\n");
  fprintf(stderr,"If the input files contain coordinate of rings, the edges\n");
  fprintf(stderr,"x_0 y_0 z_0 and x_(N-1) y_(N-1) z_(N-1) must coincide.\n");
  fprintf(stderr,"Several configurations can be given one after the other in the same input file\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"OUTPUT\n");
  fprintf(stderr,"BU_  [ -b option ]: shortest knotted portion. Bottom-up search\n");
  fprintf(stderr,"UNS_ [ -u option ]:  bottom-up search, without unknottedness check on complementar arc\n");
  fprintf(stderr,"TD_  [ -t option ]: shortest continuosly knotted portion. Top-down search\n");
  fprintf(stderr,"OUTPUT FILE FORMAT:\n RING i Adet_1 Adet_2 start end Length\n");
  fprintf(stderr," where i is the index of the ring,\n Adet_1 and Adet_2 are the Alexander determinants\n");
  fprintf(stderr," start end and length are the starting point,\n");
  fprintf(stderr," ending point and length of the knotted portion.\n" );
  fprintf(stderr," If more portions are found they are print on the same line.\n");
  fprintf(stderr,"-------------------------------------------------------\n");
  fprintf(stderr,"OPTIONS: \n");
  fprintf(stderr,"\t-h:\t\t print this help and exit.\n");
  fprintf(stderr,"\t-s <max_stride>:\t maximum stride for rectification. Default is none. Negative values in input set the stride to unlimited \n");
  fprintf(stderr,"\t-m <mem_size>:\t USE WITH CAUTION! Set the size of memory manually. Insert the expected length of the chain after simplification. \n");
  fprintf(stderr,"\t-r <seed>:\t set the pseudo random number generator's seed. Default: use time()+getpid().\n");
  fprintf(stderr,"\t-F <start>:\t (use in conjunction with -T) set the starting point for knot localization. \n");
  fprintf(stderr,"\t-T <end>:\t (use in conjunction with -F) set the ending point for knot localization.\n");
  fprintf(stderr,"\t-b:\t Perform bottom-up search. ( DEFAULT ) \n");
  fprintf(stderr,"\t-t:\t Perform top-down search.  ( DEFAULT )\n");
  fprintf(stderr,"\t-u:\t Perform bottom-up search without checking the complementar arc.\n");
  fprintf(stderr," \n");
  exit(1);
}

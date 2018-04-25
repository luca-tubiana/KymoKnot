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
#include "KNT_simplify.h"
#include "./lib/my_random.h"
#include "./lib/my_geom.h"
#include "libgen.h"

#define _VERSION_ "1.0"

#define MEMLEN 1000
#define QH_B_SIZE  16000

void print_help_rectify();
void KNT_frame2CM ( KNTarc * knt_ptr );

int main(int argc,char** argv)
{
  int cnt;
  FILE * fp_in_data;
  char filename[1024];
  KNTarc * knt_ptr;
	KNTarc * knt_rect;
	int min_stride=2;
	int max_stride=-2;
  int c;
  //extern double ** COORD_BUFFER;
  int seed = time(NULL)+getpid(); //may be overkilling...

  if(argc < 2) { print_help_rectify(); }
  sprintf(filename,"%s",argv[argc-1]);
  if ((fp_in_data=fopen(filename,"r"))==NULL)
  {
    printf("Could not open file %s .\n",argv[1]);
    exit(1);
  }
  while ((c = getopt (argc, argv, "hs:r:")) != -1)
  switch (c)
  {
    case 'h':
      print_help_rectify();
      break;
    case 's':
      max_stride = atoi(optarg);
      //min_stride = (int)floor( max_stride/pow(2,simp_sweeps));
      min_stride = 2;
      fprintf(stderr,"simplification with min_stride %d -- max_stride %d\n",min_stride,max_stride);
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

  cnt = 0;
  initialize_prng ( seed );
  /*read one chain at a time from input file. Main loop */
	while(( knt_ptr = KNTIOread_ring ( fp_in_data)) != NULL )
	{
		KNT_frame2CM (knt_ptr);
		knt_rect = KNTLrectify_coord_local ( knt_ptr,0,knt_ptr->len, min_stride,max_stride );
		KNTIOprint_ring(stdout,knt_rect);
    KNTfree_arc ( knt_rect );
		KNTfree_arc ( knt_ptr );
		cnt++;
	}

  /* close files */
  fclose(fp_in_data);

  return 0;
}

void print_help_rectify()
{
  fprintf(stderr," \n");
  fprintf(stderr,"%s %s version %s\n\nRectify a ring with a given stride [1]\n",__DATE__,__FILE__,_VERSION_);
  fprintf(stderr,"\n[1] Tubiana L., Orlandini E, Micheletti C\n");
  fprintf(stderr,"Probing the Entanglement and Locating Knots in Ring Polymers: A Comparative Study of Different Arc Closure Schemes\n");
  fprintf(stderr,"Progress of Theoretical Physics supplement, 192, 192-204 (2011)\nhttp://ptp.ipap.jp/link?PTPS/191/192\n");
  fprintf(stderr,"-------------------------------------------------------\n");
  fprintf(stderr,"usage: KNTclose.x [options] input_file\n");
  fprintf(stderr,"input file must be in the format:\n\tN\n\tx y z\n\tx y z\n\t...\n");
  fprintf(stderr,"where N is the length of the coordinate sets.\n");
  fprintf(stderr,"If the input files contain coordinate of rings, the edges\n");
  fprintf(stderr,"x_0 y_0 z_0 and x_(N-1) y_(N-1) z_(N-1) must coincide.\n");
  fprintf(stderr,"Several configurations can be given one after the other in the same input file\n");
  fprintf(stderr,"\n");
  exit(1);
}


void KNT_frame2CM ( KNTarc * knt_ptr )
{
	double CM[3]={0.,0.,0.};
	center_of_mass(knt_ptr->len,knt_ptr->coord,&CM[0]);
	for(int i=0;i<knt_ptr->len;i++)
	{
		knt_ptr->coord[i][0]-=CM[0];
		knt_ptr->coord[i][1]-=CM[1];
		knt_ptr->coord[i][2]-=CM[2];
	}

	knt_ptr->cm[0]=0;
	knt_ptr->cm[1]=0;
	knt_ptr->cm[2]=0;
	knt_ptr->flag_cm=TRUE;
}

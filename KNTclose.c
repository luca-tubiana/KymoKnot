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
#include "KNT_manager.h"


#define MEMLEN 1000
#define QH_B_SIZE  16000

void print_closure_help();

int main(int argc,char** argv)
{
  int cnt;
  FILE * fp_in_data;
  char filename[1024];
  KNTarc * arc_ptr;
	KNTarc closed_arc;
  //extern double ** COORD_BUFFER;

  if(argc < 2) { print_closure_help(); }
  sprintf(filename,"%s",argv[argc-1]);
  if ((fp_in_data=fopen(filename,"r"))==NULL)
  {
    printf("Could not open file %s .\n",argv[1]);
    exit(1);
  }

  cnt = 0;
  /*read one chain at a time from input file. Main loop */
	while(( arc_ptr = KNTIOread_linear( fp_in_data)) != NULL )
	{
  	/*allocate qhull working space*/
		qhull_init(3*arc_ptr->len);
    //buffer_init (&COORD_BUFFER,closed_arc.len );
    closed_arc = KNTCqhull_hybrid_close_subchain ( arc_ptr, arc_ptr->start , arc_ptr->end );
		KNTIOprint_ring(stdout,&closed_arc);
    KNTfree_arc ( &closed_arc );
		KNTfree_arc ( arc_ptr );
		//free_buffer ( &COORD_BUFFER );
		qhull_terminate();
		cnt++;
	}

  /* close files */
  fclose(fp_in_data);

  return 0;
}

void print_closure_help()
{
  fprintf(stderr," \n");
  fprintf(stderr,"%s %s version %s\n\nCloses a linear chain using the Minimal Interfering closure[1]\n",__DATE__,__FILE__,_VERSION_);
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




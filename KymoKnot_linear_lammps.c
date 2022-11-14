#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
#include "KNT_manager.h"



int main(int argc,char** argv)
{
	KNTid knot_type;	// knot identifier. See KNT_identify.h, KNT_table.h
  KNTarc closed_arc;
  KNTarc * knt_rect;
  KNTarc * arc_ptr;
	//char setting_string	[512];
  //int cnt;
	struct param_t param;

	kymoknot_initialize(&param,argc,argv);
  //read one ring at a time from input file -- Main loop
	while(( arc_ptr = KNTIOread_linear_lammps_version( param.fin)) != NULL )
	{
		set_search_brackets_linear(&param,param.counter,arc_ptr->len);
  	//allocate qhull working space
		qhull_init(3*(arc_ptr->len+MAX_CLS_POINTS));
		//close chain and rotate it
    closed_arc = KNTCqhull_hybrid_close_subchain ( arc_ptr, param.arc_start , param.arc_end);
		KNTLcentre_rotate_random(&closed_arc);
		//--rectification (excluding first and last bead)
		int start_local	=0;
		int end_local		=param.arc_end-param.arc_start;
		if (param.f_max_stride==FALSE) {
			param.max_stride=arc_ptr->len/50;
		}
		knt_rect = KNTLrectify_coord_local ( &closed_arc,start_local,end_local, param._min_stride,param.max_stride );
		fprintf(stderr,"closed_arc.len %d -- knt_rect->len %d\n",closed_arc.len, knt_rect->len);
		//--compute knot type of closed portion
		knot_type=KNTID_identify_knot ( knt_rect, param.kntid_ws );
		closed_arc.knot_type=knt_rect->knot_type;
		//--bracketing on rectified chain
		int start = get_idx_rect_chain 	(knt_rect,start_local);
		int end 	= get_idx_rect_chain 	(knt_rect,end_local);
		//--Begin the search
		for (int i = 0 ; i< N_SEARCHES ; i++ ) {
			if (param.search_type[i]) {
				param.search[i].st_p	=start;
				param.search[i].end_p=end;
				if(knot_type.k_id == K_Un) {
					int bfs=128;
					char knot_ids[bfs];
					KNTID_print_knot(knot_ids,bfs,knot_type);
					fprintf(param.search[i].fout,"%d \t%s %d %d %d \n",param.counter, knot_ids, -1,-1,-1);
					fflush(param.search[i].fout);
				} else {
					param.search[i].LocFnc_ptr (&closed_arc, knt_rect,param.search[i].st_p,param.search[i].end_p, KNTCqhull_hybrid_close_subchain, param.kntid_ws);
					print_search_results_linear 		(&closed_arc,&param.search[i],param.counter, &param);
				}
			}
		}
    KNTfree_arc ( &closed_arc );
		KNTfree_arc ( arc_ptr );
		KNTfree_arc ( knt_rect );
		qhull_terminate();
		param.counter++;
	}
	kymoknot_terminate(&param);
  return 0;
}

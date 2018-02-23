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
  KNTarc * knt_rect;
  KNTarc * knt_ptr;
	//char setting_string	[512];
  //int cnt;
	struct param_t param;

	kymoknot_initialize(&param,argc,argv);
  //read one ring at a time from input file -- Main loop
	while(( knt_ptr = KNTIOread_ring( param.fin)) != NULL )
	{
		set_search_brackets_ring(&param,param.counter,knt_ptr->len);
  	//allocate qhull working space
		qhull_init(3*(knt_ptr->len+MAX_CLS_POINTS));
		//close chain and rotate it
		KNTLrotate_random(knt_ptr);
		//--rectification (excluding first and last bead)
		int start_local;
		int end_local;
		//XXX this condition needs to be improved
		if ( param.f_arc_start || param.f_arc_end) { 
			start_local = param.arc_start;
			end_local = param.arc_end;
		}
		else {
			start_local = 0;
			end_local 	= knt_ptr->len-1;
			param.arc_start=start_local;
			param.arc_end=end_local;
		}

		if (param.f_max_stride==FALSE) { 
			param.max_stride=knt_ptr->len/50;
		}
		knt_rect = KNTLrectify_coord_local ( knt_ptr,start_local,end_local, param._min_stride,param.max_stride );
		int start = get_idx_rect_chain 	(knt_rect,start_local);
		int end 	= get_idx_rect_chain 	(knt_rect,end_local);
		//
		fprintf(stderr,"knt_ptr->len %d -- knt_rect->len %d\n",knt_ptr->len, knt_rect->len);
		//--compute knot type of closed portion
		knot_type=KNTID_identify_knot ( knt_rect, param.kntid_ws );
		knt_ptr->knot_type=knt_rect->knot_type;
		//--bracketing on rectified chain
		//--Begin the search
		for (int i = 0 ; i< N_SEARCHES ; i++ ) {
			if (param.search_type[i]) {
				if(param.f_arc_start || param.f_arc_end) {
					param.search[i].st_p	=start;
					param.search[i].end_p	=end;
				} else {
					param.search[i].st_p	=DONT_CARE;
					param.search[i].end_p	=DONT_CARE;
				}
				if(knot_type.k_id == K_Un) {
					int bfs=128;
					char knot_ids[bfs];
					KNTID_print_knot(knot_ids,bfs,knot_type);
					fprintf(param.search[i].fout,"%d \t%s %d %d %d \n",param.counter, knot_ids, DONT_CARE, DONT_CARE, DONT_CARE);
					fflush(param.search[i].fout);
				} else {
					param.search[i].LocFnc_ptr (knt_ptr, knt_rect,param.search[i].st_p,param.search[i].end_p, KNTCqhull_hybrid_close_subchain, param.kntid_ws);
					print_search_results_ring 		(knt_ptr,&param.search[i],param.counter, &param);
				}
			}
		}
    KNTfree_arc ( knt_ptr );
		KNTfree_arc ( knt_rect );
		qhull_terminate();
		param.counter++;
	}
	kymoknot_terminate(&param);
  return 0;
}

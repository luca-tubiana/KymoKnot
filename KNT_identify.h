//09-11-2017 LT
//This header provides knot determination functions. In the current
//implementation knots are identified using the Alexander Determinants in
//-1 and -2. Change the body of  KNTID_identify_knot to implement other
//knot invariants. Modify the two structures and KNT_id_table.h accordingly.
//
#ifndef HDR_KNT_IDENTIFY
#define HDR_KNT_IDENTIFY

#include "KNT_table.h"
#include "KNT_arc.h"
#include "Alexander.h"

// Modify the following structure to change knot determination.
struct  knot_det_workspace{
	KNTid *known_knots;
	KNTid  target_knot;
	double **coord_buffer;
	ALX_wspace *alx_wspace; //memory used by Alexander determinants computation
};
typedef struct knot_det_workspace KNTID_wspace;

// Modify the following structure to change KNTID_wspace initial parameters
struct  knot_det_init_var{
	int alex_dim; 	//expected size of crossing matrix
	int buffer_dim; //expected length of simplified chain
};
typedef struct knot_det_init_var KNTID_ws_var;


KNTID_wspace * KNTID_wspace_init 		( KNTID_ws_var *init);
void 		KNTID_free_wspace 		( KNTID_wspace *ws	);
void 		KNTID_set_target_knot	(	KNTID_wspace *ws, KNTid target	);
void 		KNTID_unset_target_knot			(	KNTID_wspace *ws	);
KNTid	 	KNTID_identify_knot 				( KNTarc *knt_ptr, KNTID_wspace *kid_ws );

KNTid KNTID_get_knot_from_id (int k_type);
void KNTID_get_rolfsen (char *rolf_id,int bfs, KNTid K);
void KNTID_print_knot (char *knot_ids,int bfs, KNTid K);
void KNTID_print_unknot (char *knot_ids,int bfs);

#endif  //HDR_KNT_IDENTIFY

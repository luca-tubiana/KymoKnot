/**********************************************************
 * LT 02-03-2011                                          *
 * KNT_lib: prototypes of all functions related to knot   *
 * localization.                                          *
 * 1. Closure schemes;                                    *
 * 2. Knot matrix determination;                          *
 * 3. knot localization schemes;                          *
 * 4. auxiliary functions.                                *
 *                                                        *
 * KNOWN BUGS                                             *
 *                                                        *
 * KNTLqhull_close_subchain fails if start == end !       *
 *                                                        *
 * ********************************************************/

#ifndef HDR_KNT_LIB
#define HDR_KNT_LIB

#include "KNT_arc.h"
#include "KNT_identify.h"
//#include "projections.h"
#include "Alexander.h"

#define DEBUG 0

/*
 * Knot determination and knot localization schemes
 */
int     KNTLknot_determination ( KNTarc * knt_ptr, ALX_wspace * alx_wspace );
/* knot matrix evaluation    */
void    KNTLkntmatrix ( KNTarc * knt_ptr, KNTarc (*close_subchain) ( KNTarc *, int, int ), ALX_wspace * alx_wspace);
/* knot localization schemes with simplification aliasing */
void 		KNTLloc_shrt_knot_rect1
			( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), ALX_wspace * alx_wspace );
void 		KNTLloc_shrtcnt_knot_rect1 
			( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), ALX_wspace * alx_wspace);
void 		KNTLloc_shrt_knot_unsafe_rect1
			( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), ALX_wspace * alx_wspace );

void KNTL_BUloc_rect1  ( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws );
void KNTL_TDloc_rect1  ( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws );
void KNTL_UNSloc_rect1 ( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws );

// These functions shoud be placed somewhere else...
/* MEMORY MANAGEMENT */
void buffer_init ( double ***buff, int buffer_dim ) ;
void free_buffer ( double ***buff);

/* return id of knot from alexander determinants. ids are in KNT_defaults.h */
int  KNTLknot_id ( int dets[2] );
/* rotate knot to change projection*/
void KNTLrotate ( KNTarc * knt_ptr, double axis[3], double theta);
void KNTLcentre_rotate_random ( KNTarc * knt_ptr );
#endif /*HDR_KNT_LIB */

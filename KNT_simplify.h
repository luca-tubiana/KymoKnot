#ifndef HDR_KNT_SMP
#define HDR_KNT_SMP
#include "KNT_arc.h"
void   copy_chain              ( double ** coord, int len, double ** coordnew );
/* check if the movement of a bead does not affect topology */
int    check_viable_displacement_prd
       ( double  ** coord, int nsteps, int bead_moved, double *moved_bead_coordinate );
int    check_viable_displacement_sample
       ( double  ** coord, int * sample, int n_sample, int idx_bead_moved, double *moved_bead_coordinate);
/* rectifcation procedures on  chain and KNTarc */
void   chain_remove_beads_new
       ( int oldlen, double ** oldcoord, int *newlen,  double ** coord,  int *index  , int max_stride);
//void chain_remove_beads_w_shuffle
 //      ( int oldlen, double ** oldcoord, int *newlen, double ** coord,  int max_stride);
void chain_remove_beads_w_shuffle_nostride
      ( int oldlen, double ** oldcoord, int *newlen, double ** coord);
int chain_remove_beads_local
       ( int oldlen, double ** oldcoord,int start,int end, int *newlen, double ** coord, int * index,int min_stride, int max_stride);
KNTarc * KNTLrectify_coord ( KNTarc * knt_ptr, int max_stride );
KNTarc * KNTLrectify_coord_local ( KNTarc * knt_ptr, int st_p, int end_p, int min_stride, int max_stride );
#endif //HDF_KNT_SMP

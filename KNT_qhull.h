#ifndef KNT_HDR_QH
#define KNT_HDR_QH
#include "qhull_a.h"
/* qhull related functions */
void   qhull_init          ( int );
void   qhull_buffer_resize ( int );
void   qhull_free_mem   (     );
void   qhull_terminate  (     );
double qhull_dist_facet ( double p[3], double normalized_out_dir[3]);
#endif

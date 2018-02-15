#ifndef HDR_KNT_CLS
#define HDR_KNT_CLS
#include "KNT_arc.h"
/*
 * Closure schemes
 */
#define MAX_CLS_POINTS 15
#define MIN_CLS_POINTS 5
KNTarc  KNTCqhull_hybrid_close_subchain ( KNTarc * ring_ptr, int start, int end );
KNTarc  KNTCqhull_close_subchain        ( KNTarc * ring_ptr, int start, int end );
KNTarc  KNTCrandom_close_subchain       ( KNTarc * ring_ptr, int start, int end );
KNTarc  KNTCradial_close_subchain       ( KNTarc * ring_ptr, int start, int end );
KNTarc  KNTCbridge_close_subchain       ( KNTarc * ring_ptr, int start, int end );
/*
 * Auxiliary functions
 */
void great_circle_path(double A[3], double B[3], double C[3], int n, double **coord_buffer);
/*
 * random closure auxiliary functions
 */

void KNTLreset_random_closure( int N_cls, double R_fact, double tresh );
void uniform_spherical_distribution( double point[3] );
int    extract_subchain        ( int N, double  ** chain, int start, int end, double ** subchain );
#endif

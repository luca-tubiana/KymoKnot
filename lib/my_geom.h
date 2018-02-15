
#ifndef HDR_GEOM
#define HDR_GEOM

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif
/* geometric routines */
void vecprod_d (const double *a, const double *b, double *c);
double scal_d (const double * restrict a, const double * restrict b, int dim);
double norm_d (const double *a, int dim);
void normalize_d (double * restrict a, int dim);
double dist_d (const double *a, const double *b, int dim);
double dist_segments(const double p0[3], const double p1[3], const double p2[3], const double p3[3]);
int LineFacet(const double * restrict p1, const double * restrict p2, const double * restrict pa, const double * restrict pb, const double * restrict pc, double* restrict p);
int LineFacetOLD( double *p1, double *p2, double *pa, double *pb, double *pc, double *p);
void center_of_mass( int N, double ** coord, double *cm );
double find_radius(int N,double ** coord,double center[3]);

#endif

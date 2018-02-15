#include "KNT_qhull.h"
#include "KNT_defaults.h"
#include "my_geom.h"
#include "my_memory.h"

/*--------Qhull global variables-----*/
double * qhull_buffer;                /* memory for coordinates for quickhull evaluation */
char     qhull_flags[256];            /* flags with which call qhull()                   */
boolT    qhull_ismalloc;
int      qhull_curlong;
int      qhull_totlong;
int      qhull_is_init = FALSE;        /* keep track of qhull_buffer memory state. Use it to avoid memory leaks       */

/*
 * qhull_init
 *
 * Initializes memory for quickhull.
 */
void qhull_init (int qhull_buffer_dim)
{
  extern char     qhull_flags[256];
  extern double * qhull_buffer;
  extern boolT    qhull_ismalloc;
  extern int      qhull_is_init;

  if(qhull_is_init == 0)
  {
    qhull_ismalloc = FALSE;

    sprintf (qhull_flags, "qhull Qt Fa");
    qhull_buffer = d1t(qhull_buffer_dim);
    qhull_is_init = 1;
  }

}
void qhull_buffer_resize ( int qhull_new_buffer_dim )
{
  extern char     qhull_flags[256];
  extern double * qhull_buffer;
  extern boolT    qhull_ismalloc;
  extern int      qhull_is_init;
  if ( qhull_is_init )
  {
    free_d1t( qhull_buffer );
    qhull_buffer = d1t ( qhull_new_buffer_dim );
  }
  else
  {
    failed (" Trying to reallocate qhull buffer vector when qhull is not initialized!");
  }
}
void qhull_free_mem()
{

  extern int      qhull_curlong;
  extern int      qhull_totlong;

  qh_freeqhull(!qh_ALL);                   /* free long memory  */
  qh_memfreeshort (&qhull_curlong, &qhull_totlong);    /* free short memory and memory allocator */

  if (qhull_curlong || qhull_totlong)
    fprintf (stderr, "qhull internal warning (user_eg, #1): did not free %d bytes of long memory (%d pieces)\n", qhull_totlong, qhull_curlong);

}

void qhull_terminate ( )
{
  extern boolT    qhull_ismalloc;
  extern int      qhull_curlong;
  extern int      qhull_totlong;
  extern double * qhull_buffer;
  extern int      qhull_is_init;

  if(qhull_is_init)
  {
    qh_freeqhull(!qh_ALL);                   /* free long memory  */
    qh_memfreeshort (&qhull_curlong, &qhull_totlong);    /* free short memory and memory allocator */

    if (qhull_curlong || qhull_totlong)
      fprintf (stderr, "qhull internal warning (user_eg, #1): did not free %d bytes of long memory (%d pieces)\n", qhull_totlong, qhull_curlong);

    free_d1t(qhull_buffer);
    qhull_is_init = 0;
  }

}

/*
 * qhull_dist_facet
 *
 * Returns the distance from point p
 * to the nearest point on the qhull.
 * Stores the outward direction
 * in normalize_out_dir.
 *
 * This function is a wrapper for qh_projectpoint.
 */
double qhull_dist_facet ( double p[3], double normalized_out_dir[3] )
{
  int i;
  facetT *facet     = NULL;
  pointT *point     = NULL;
  pointT *prj_point = NULL;
  double dist,min_dist;
  min_dist=1000000;

  point = &p[0];

  FORALLfacets {
    if(facet->f.area > 0){
      qh_distplane(point, facet, &dist);
      //dist = distPointFacet(p,facet,q);
      if(dist < KNT_EPSIL && fabs(dist) < min_dist)
      {
        if( fabs(dist) < KNT_EPSIL )
        {
          normalized_out_dir[0] = 0.0;
          normalized_out_dir[1] = 0.0;
          normalized_out_dir[2] = 0.0;
          return 0.0;
        }
        min_dist =  fabs(dist);
        prj_point = qh_projectpoint(point,facet,dist);
      }
      else if(dist > KNT_EPSIL)
        fprintf(stderr,"positive distance from hull! %12.8lf\n",dist);

    }
  }
  for ( i = 0 ; i < 3 ; i++)
  {
    normalized_out_dir[i] = prj_point[i] - p[i];
  }
  normalize_d (normalized_out_dir,3);
  return min_dist;
}

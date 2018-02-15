#include "KNT_closures.h"
#include "KNT_defaults.h"
#include "my_geom.h"
#include "my_memory.h"
#include "my_random.h"
#include "KNT_qhull.h"

/*
 * GLOBAL VARIABLES
 *
 * Defining here the global variables used by the functions keeps
 * them hidden from the final user.
 */
/*--------KNTarc global variables----*/
extern KNTarc KNTarc_DEFAULT;         /* defined in KNT_arc.c */
/*--------Qhull global variables-----*/
extern double * qhull_buffer;                /* memory for coordinates for quickhull evaluation */
extern char     qhull_flags[256];            /* flags with which call qhull()                   */
extern boolT    qhull_ismalloc;
extern int      qhull_is_init;        /* keep track of qhull_buffer memory state. Use it to avoid memory leaks       */
/*-------Stochastic closure values---*/
double   stch_close_fact = 10;         /* close on a sphere stch_close_fact times bigger than arc's enclosing sphere. */


int      stch_n_closures = 1000;       /* number of different closure (default)                                       */
int      stch_is_init    = FALSE;      /* not inizialized: default values used;                                       */
double   stch_treshold   = 0.5;        /* If less than stch_treshold closed arcs result in the same knot, the topology is left as uncertain */

/*
 * Closure schemes
 */

/*
 * KNTCqhull_hybrid_close_subchain
 *
 * Closes an arc {r_i,...,r_j} with a minimal entanglement
 * closure trough convex hull. The function evaluates first
 * the convex hull of the arc, then the distances of the arc
 * two termini from the convex hull. If the sum of these
 * distances is less than than the distance between the two
 * termini, the arc is closed outside the convex hull, piercing it
 * in the points nearest to the two termini; otherwise
 * the two termini are directly joined.
 *
 * IN:
 *  KNTarc * ring_ptr: ring on which we operate
 *  int start: starting bead of the arc we want to close,
 *  int end:   final bead of the arc we want to close.
 * OUT:
 *  a KNTarc struct with the closed arc stored.
 */

KNTarc  KNTCqhull_hybrid_close_subchain ( KNTarc * ring_ptr, int start, int end)
{
  int       i, j;
  int       closed_len;           /* length of closed ring array */
  int       exitcode;             /* internal use by qhull()     */
  int       qhull_local_init = 0;
  int       cls_points;       /* number of closure added points    */

  FILE   *  qhull_out;            /* qhull output here                 */

  double    theta, dth, phi;
  double    cm[3];                /* center of mass                    */
  double    v_1[3],v_2[3],v_3[3];  /* vectors to closure points         */
  double    R_close;              /* closure points distance from cm   */
  double    radius;               /* arc's radius                      */
  double    dist_start;           /* dist from start to convex hull    */
  double    dist_end;             /* dist from end  to convex hull     */
  double    dist_start_end;       /* distance between termini          */
  double ** coord_buffer;
  KNTarc    arc = KNTarc_DEFAULT;

  /*See global variables at the beginning of this file                 */
  extern double  * qhull_buffer;
  extern boolT     qhull_ismalloc;
  extern char      qhull_flags[256];
  extern long int     * ptr_idum;

  /* check ring_ptr correct initialization */
  if( ring_ptr->is_init != 1 || ring_ptr->flag_len != 1 || ring_ptr->coord == NULL )
  {
    failed ( "KNTCqhull_hybrid_close_subchain. ring_ptr is not correctly initialized!\n");
  }

  /* if qhull not initialized, initialize it */
  if(!qhull_is_init)
  {
    qhull_init( ring_ptr->len * 3 );
    qhull_local_init = 1;
  }
  /* extract the subchain between start and end, included */
	/*
	 * 09-02-2017 (LT). I had to change this since it might cause a segfault on
	 * COORD_BUFFER. Specifically: if one tries to close a subportion of linear
	 * chain which has previously been closed, cls_points will be based on the
	 * length of the whole, closed, chain. if the subportion coincides with the
	 * linear chain, then cls_points  will be higher than the number of points
	 * initially used to close the chain and to set the size of COORD_BUFFER.
	 */
	/*
  cls_points = (int)floor( ring_ptr->len / 10);
  if ( cls_points > MAX_CLS_POINTS ) { cls_points = MAX_CLS_POINTS; }
  else if ( cls_points < MIN_CLS_POINTS) { cls_points = MIN_CLS_POINTS; }
	*/
	if(ring_ptr->len> 5*MAX_CLS_POINTS)
	{
		cls_points=MAX_CLS_POINTS;
	}
	else
	{
		cls_points=MIN_CLS_POINTS;
	}
  /* initialize coord_buffer to store closed arc */
  coord_buffer = d2t(ring_ptr->len + cls_points + 1, 3);
  //arc = KNTinit( );
  closed_len = extract_subchain ( ring_ptr->len, ring_ptr->coord, start, end, coord_buffer );
  //cls_points = (int)floor( closed_len / 10);
  //if ( cls_points < 5 ) { cls_points = 5; }

  if( closed_len < 4 )
  {
    free_d2t(coord_buffer);
    failed("need at lest 4 points for a convex hull!");
  }
  for( i = 0 ; i < closed_len ; i++)
  {
    for ( j = 0 ; j < 3 ; j++)
    {
      qhull_buffer[3 * i + j] = coord_buffer[i][j];
    }
  }

  /* set qhull() output to /dev/null. */
  if ( ( qhull_out = fopen("/dev/null","r") ) == NULL )
  {
    printf("Could not open /dev/null .\n");
    exit(1);
  }
  /*
   * Evaluated convex hull. qh_new_qhull() store everything in a global structure.
   * see libhull.h for details.
   */
  exitcode = qh_new_qhull (3, closed_len, qhull_buffer, qhull_ismalloc, qhull_flags, qhull_out,stderr);
  fclose ( qhull_out );

  if ( exitcode )
  {
    free_d2t(coord_buffer);
    failed("KNTCqhull_hybrid_close_subchain: qhull failure!\n");
  }

  dist_start_end = dist_d           (coord_buffer[0],coord_buffer[(closed_len-1)], 3 );
  dist_start     = qhull_dist_facet (coord_buffer[0],                v_1);
  dist_end       = qhull_dist_facet (coord_buffer[(closed_len - 1)], v_2);

  normalize_d(v_1,3);
  normalize_d(v_2,3);

  center_of_mass      ( closed_len, coord_buffer, cm );
  radius = find_radius( closed_len, coord_buffer, cm );
  /* Play safe */
  R_close = 3 * radius;

  /*
   * If one of the points is on the convex hull,
   * use a radial projection to exit and close.
   */
  if ( fabs ( dist_start ) < KNT_EPSIL )
  {
    for ( i = 0 ; i < 3 ; i++)
    {
      v_1[i] =coord_buffer[0][i] - cm[i];
    }
    normalize_d(v_1,3);
  }


  if ( fabs(dist_end) < KNT_EPSIL )
  {
    for ( i = 0 ; i < 3 ; i++)
    {
      v_2[i] =coord_buffer[(closed_len - 1)][i] - cm[i];
    }
    normalize_d(v_2,3);
  }

  /*
   * If dist_start + dist_end < dist_start_end, close the arc with 3 points.
   * To avoid intersections of the closure segments with the chain, closure
   * points have to lie on a sphere centered on cm with radius > sqrt(2) * radius.
   */


  if(dist_start+dist_end < dist_start_end)
  {
    //center of mass must be recomputed for the subchain of interest
    //i vettori v_1 e v_2 vanno rappresentati entrambi nello spazio affine del cm della catena!

    double alpha,beta,A2,B2,Aa,Bb;
    double A[3],B[3];
    A[0]=coord_buffer[0][0]-cm[0];
    A[1]=coord_buffer[0][1]-cm[1];
    A[2]=coord_buffer[0][2]-cm[2];
    B[0]=coord_buffer[closed_len - 1][0]-cm[0];
    B[1]=coord_buffer[closed_len - 1][1]-cm[1];
    B[2]=coord_buffer[closed_len - 1][2]-cm[2];
    //choose alpha and beta such that vec(A)+alpha*vec(v_1) and vec(B)+beta*vec(v_2) are both
    //on a circle of radius R_close from the center of mass.
    A2 = scal_d(A,A,3);
    B2 = scal_d(B,B,3);
    Aa = scal_d(A,v_1,3);
    Bb = scal_d(B,v_2,3);
		//alpha and beta are obtained from the cosine theorem:
		//R^2=A^2+alpha^2 +2*|A|*alpha* scal_d(A,alpha*v_1)/(|A|*alpha)
		//(The plus sign is given by the orientation of the vector A)
    alpha = -Aa + sqrt(Aa*Aa + R_close*R_close - A2 );
    beta  = -Bb + sqrt(Bb*Bb + R_close*R_close - B2 );
    //update A and B
    A[0] += alpha*v_1[0];
    A[1] += alpha*v_1[1];
    A[2] += alpha*v_1[2];
    B[0] += beta*v_2[0];
    B[1] += beta*v_2[1];
    B[2] += beta*v_2[2];
		/*
    Aa = scal_d(A,v_1,3)/norm_d(A,3);
    theta = scal_d(A,B,3)/norm_d(B,3);
    //double use of v_1 and v_2
    v_2[0] = B[0];
    v_2[1] = B[1];
    v_2[2] = B[2];
    normalize_d(v_2,3); //questo mi convince molto poco!! :(
    v_1[0] = A[0] - theta*v_2[0];
    v_1[1] = A[1] - theta*v_2[1];
    v_1[2] = A[2] - theta*v_2[2];
    normalize_d(v_1,3);
    vecprod_d ( v_1, v_2, v_3);
    theta = theta/norm_d(A,3);
    theta = acos ( theta );
    dth = theta / cls_points;
    theta = 0.0;
    coord_buffer[closed_len][0] = B[0] + cm[0];
    coord_buffer[closed_len][1] = B[1] + cm[1];
    coord_buffer[closed_len][2] = B[2] + cm[2];
    for ( i = 1 ; i < cls_points-1; i++ )
    {
      phi = PI/2 - PI/40 + ran2(ptr_idum)*PI/20;
      theta += dth;
      closed_len++;
      coord_buffer[closed_len][0]= R_close * cos(theta) * sin(phi) * v_2[0] + R_close * sin(theta) * sin(phi) * v_1[0] + R_close * cos(phi) * v_3[0] + cm[0];
      coord_buffer[closed_len][1]= R_close * cos(theta) * sin(phi) * v_2[1] + R_close * sin(theta) * sin(phi) * v_1[1] + R_close * cos(phi) * v_3[1] + cm[1];
      coord_buffer[closed_len][2]= R_close * cos(theta) * sin(phi) * v_2[2] + R_close * sin(theta) * sin(phi) * v_1[2] + R_close * cos(phi) * v_3[2] + cm[2];
    }
    closed_len++;
    coord_buffer[closed_len][0] = A[0] + cm[0];
    coord_buffer[closed_len][1] = A[1] + cm[1];
    coord_buffer[closed_len][2] = A[2] + cm[2];
    closed_len++;
		*/
		great_circle_path(A, B, cm, cls_points, &coord_buffer[closed_len]);
		closed_len+=cls_points;

#if DEBUG == 1
    fprintf(stderr,"%4d\n",closed_len+1);
    for ( i = 0 ; i < closed_len ; i++ )
    {
      fprintf(stderr, "%lf %lf %lf\n",coord_buffer[i][0],
                                      coord_buffer[i][1],
                                      coord_buffer[i][2]);
    }
    fprintf(stderr, "%lf %lf %lf\n",coord_buffer[0][0],
                                    coord_buffer[0][1],
                                    coord_buffer[0][2]);
#endif

  }
  /* save everything in arc */
  KNTadd_coord ( closed_len, coord_buffer, NULL, &arc );
  KNTarc_SET_value(&arc, arc_type, ARC_ID_ANY, char);
  KNTarc_SET_value(&arc, start, start, int);
  KNTarc_SET_value(&arc, end,   end,   int);
  KNTarc_SET_value(&arc, Rc, radius, double);
  for ( i = 0 ; i < 3 ; i++ )
  {
    arc.cm[i] = cm[i];
  }
  arc.flag_cm = TRUE;
  strncpy(arc.closure,QHULLCLOSUREHYB,strlen(QHULLCLOSUREHYB));

  /* free memory */
  free_d2t(coord_buffer);
  qhull_free_mem();
  if( qhull_local_init )
  {
    qhull_terminate();
  }

  return arc;
}

/*
 * KNTCqhull_close_subchain
 *
 * Closes an arc {r_i,...,r_j} with a   closure trough convex hull.
 * The function evaluates the convex hull of the arc and the nearest
 * point to each terminus on the convex hull, through which the arc
 * is closed outside the hull.
 *
 * IN:
 *  KNTarc * ring_ptr: ring on which we operate
 *  int start: starting bead of the arc we want to close,
 *  int end:   final bead of the arc we want to close.
 * OUT:
 *  a KNTarc struct with the closed arc stored.
 */
KNTarc  KNTCqhull_close_subchain ( KNTarc * ring_ptr, int start, int end)
{
  int       i, j;
  int       closed_len;           /* length of closed ring array */
  int       exitcode;             /* internal use by qhull()     */
  int       qhull_local_init = FALSE;
  int       cls_points;       /* number of closure added points    */

  FILE   *  qhull_out;            /* qhull output here                 */

  double    cm[3];                /* center of mass                    */
  double    v_1[3],v_2[3],v_3[3]; /* vectors to closure points         */
  double    R_close;              /* closure points distance from cm   */
  double    radius;               /* arc's radius                      */
  double    dist_start;           /* dist from start to convex hull    */
  double    dist_end;             /* dist from end  to convex hull     */
  double ** coord_buffer;
  KNTarc    arc = KNTarc_DEFAULT;

  /*See global variables at the beginning of this file                 */
  extern double  * qhull_buffer;
  extern boolT     qhull_ismalloc;
  extern char      qhull_flags[256];

  /* check ring_ptr correct initialization */
  if( ring_ptr->is_init != 1 || ring_ptr->flag_len != 1 || ring_ptr->coord == NULL )
  {
    failed ( "KNTCqhull_close_subchain. ring_ptr is not correctly initialized!\n");
  }

  /* if qhull not initialized, initialize it */
  if(!qhull_is_init)
  {
    qhull_init( ring_ptr->len * 3 );
    qhull_local_init = 1;
  }

  cls_points = (int)floor( ring_ptr->len / 10);
  if ( cls_points > MAX_CLS_POINTS ) { cls_points = MAX_CLS_POINTS; }
  else if ( cls_points < MIN_CLS_POINTS) { cls_points = MIN_CLS_POINTS; }
  /* initialize coord_buffer to store closed arc */
  coord_buffer = d2t(ring_ptr->len + cls_points + 1, 3);
  //arc = KNTinit( );
  closed_len = extract_subchain ( ring_ptr->len, ring_ptr->coord, start, end, coord_buffer );
  if( closed_len < 4 )
  {
    free_d2t(coord_buffer);
    failed("need at lest 4 points for a convex hull!");
  }
  for( i = 0 ; i < closed_len ; i++)
  {
    for ( j = 0 ; j < 3 ; j++)
    {
      qhull_buffer[3 * i + j] = coord_buffer[i][j];
    }
  }

  /* set qhull() output to /dev/null. */
  if ( ( qhull_out = fopen("/dev/null","r") ) == NULL )
  {
    printf("Could not open /dev/null .\n");
    exit(1);
  }
  /*
   * Evaluated convex hull. qh_new_qhull() store everything in a global structure.
   * see libhull.h for details. Positive values of exitcode mean an error has occurred.
   */
  exitcode = qh_new_qhull (3, closed_len, qhull_buffer, qhull_ismalloc, qhull_flags, qhull_out,stderr);
  fclose ( qhull_out );

  if ( exitcode )
  {
    free_d2t(coord_buffer);
    failed("KNTCqhull_close_subchain: qhull failure!\n");
  }


  dist_start     = qhull_dist_facet (coord_buffer[0],                v_1);
  dist_end       = qhull_dist_facet (coord_buffer[(closed_len - 1)], v_2);
  normalize_d(v_1,3);
  normalize_d(v_2,3);

  center_of_mass      ( closed_len, coord_buffer, cm );
  radius = find_radius( closed_len, coord_buffer, cm );
  R_close = 3 * radius;

  /*
   * If one of the points is on the convex hull,
   * use a radial projection to exit and close.
   */
  if ( fabs ( dist_start ) < KNT_EPSIL )
  {
    for ( i = 0 ; i < 3 ; i++)
    {
      v_1[i] =coord_buffer[0][i] - cm[i];
    }
    normalize_d(v_1,3);
  }


  if ( fabs(dist_end) < KNT_EPSIL )
  {
    for ( i = 0 ; i < 3 ; i++)
    {
      v_2[i] =coord_buffer[(closed_len - 1)][i] - cm[i];
    }
    normalize_d(v_2,3);
  }

  //center of mass must be recomputed for the subchain of interest
  //i vettori v_1 e v_2 vanno rappresentati entrambi nello spazio affine del cm della catena!

  double alpha,beta,A2,B2,Aa,Bb;
  double A[3],B[3];
  A[0]=coord_buffer[0][0]-cm[0];
  A[1]=coord_buffer[0][1]-cm[1];
  A[2]=coord_buffer[0][2]-cm[2];
  B[0]=coord_buffer[closed_len - 1][0]-cm[0];
  B[1]=coord_buffer[closed_len - 1][1]-cm[1];
  B[2]=coord_buffer[closed_len - 1][2]-cm[2];
  //choose alpha and beta such that vec(A)+alpha*vec(v_1) and vec(B)+beta*vec(v_2) are both
  //on a circle of radius R_close from the center of mass.
  A2 = scal_d(A,A,3);
  B2 = scal_d(B,B,3);
  Aa = scal_d(A,v_1,3);
  Bb = scal_d(B,v_2,3);
	//alpha and beta are obtained from the cosine theorem:
	//R^2=A^2+alpha^2 +2*|A|*alpha* scal_d(A,alpha*v_1)/(|A|*alpha)
	//(The plus sign is given by the orientation of the vector A)
  alpha = -Aa + sqrt(Aa*Aa + R_close*R_close - A2 );
  beta  = -Bb + sqrt(Bb*Bb + R_close*R_close - B2 );
  //update A and B
  A[0] = A[0] + alpha*v_1[0];
  A[1] = A[1] + alpha*v_1[1];
  A[2] = A[2] + alpha*v_1[2];
  B[0] = B[0] + beta*v_2[0];
  B[1] = B[1] + beta*v_2[1];
  B[2] = B[2] + beta*v_2[2];
	great_circle_path(A, B, cm, cls_points, &coord_buffer[closed_len]);
	closed_len+=cls_points;
#if DEBUG == 1
  fprintf(stderr,"%4d\n",ring_ptr->len + 4);
  for ( i = 0 ; i < closed_len + 3; i++ )
  {
    fprintf(stderr, "%lf %lf %lf\n",coord_buffer[i][0],
                                    coord_buffer[i][1],
                                    coord_buffer[i][2]);
  }
  for ( i = closed_len + 3 ; i < ring_ptr->len + 4; i++ )
  {
    fprintf(stderr, "%lf %lf %lf\n",coord_buffer[0][0],
                                    coord_buffer[0][1],
                                    coord_buffer[0][2]);
  }
#endif
  /* save everything in arc */
  KNTadd_coord ( closed_len, coord_buffer, NULL, &arc );
  KNTarc_SET_value(&arc, arc_type, ARC_ID_ANY, char);
  KNTarc_SET_value(&arc, start, start, int);
  KNTarc_SET_value(&arc, end,   end,   int);
  KNTarc_SET_value(&arc, Rc, radius, double);
  for ( i = 0 ; i < 3 ; i++ )
  {
    arc.cm[i] = cm[i];
  }
  arc.flag_cm = TRUE;
  strncpy(arc.closure,QHULLCLOSUREHYB,strlen(QHULLCLOSUREHYB));

  /* free memory */
  free_d2t(coord_buffer);
  qhull_free_mem();
  if( qhull_local_init )
  {
    qhull_terminate();
  }

  return arc;
}

/*
 * KNTCrandom_close_subchain
 *
 * Closes an arc {r_i,...,r_j} with a random point on a sphere of
 * radius R_close.
 *
 * IN:
 *  KNTarc * ring_ptr: ring on which we operate
 *  int start: starting bead of the arc we want to close,
 *  int end:   final bead of the arc we want to close.
 * OUT:
 *  a KNTarc struct with the closed arc stored.
 */
KNTarc  KNTCrandom_close_subchain   ( KNTarc * ring_ptr, int start, int end )
{
  int       j;
  int       closed_len;           /* length of closed ring array */
  int       cls_points = 1;       /* number of closure added points    */

  double    cm[3];                /* center of mass                    */
  double    closure_point[3];
  double    R_close;              /* closure points distance from cm   */
  double    radius;               /* arc's radius                      */
  double ** coord_buffer;
  KNTarc    arc = KNTarc_DEFAULT;

  extern double stch_close_fact;


  /* check ring_ptr correct initialization */
  if( ring_ptr->is_init != 1 || ring_ptr->flag_len != 1 || ring_ptr->coord == NULL )
  {
    failed ( "KNTCrandom_close_subchain. ring_ptr is not correctly initialized!\n");
  }

  /* initialize coord_buffer to store closed arc */
  coord_buffer = d2t(ring_ptr->len + cls_points, 3);
  //arc = KNTinit( );

  /* extract the subchain between start and end, included */
  closed_len = extract_subchain ( ring_ptr->len, ring_ptr->coord, start, end, coord_buffer );
  uniform_spherical_distribution ( closure_point );
  center_of_mass      ( closed_len, coord_buffer, cm );
  radius = find_radius( closed_len, coord_buffer, cm );
  R_close = radius * stch_close_fact;

  for ( j = 0 ; j < 3 ; j++ )
  {
    closure_point[j] = closure_point[j] * R_close + cm[j];
    coord_buffer[closed_len][j] = closure_point[j];
  }

  closed_len += cls_points;

  /* save everything in arc */
  KNTadd_coord ( closed_len, coord_buffer, NULL, &arc );
  KNTarc_SET_value(&arc, arc_type, ARC_ID_ANY, char);
  KNTarc_SET_value(&arc, start, start, int);
  KNTarc_SET_value(&arc, end,   end,   int);
  KNTarc_SET_value(&arc, Rc, radius, double);
  for ( j = 0 ; j < 3 ; j++ )
  {
    arc.cm[j] = cm[j];
  }
  arc.flag_cm = TRUE;
  strncpy(arc.closure,STCHCLOSURE,strlen(STCHCLOSURE));
#if DEBUG == 4
    fprintf(stderr,"%4d\n",ring_ptr->len + 1);
    for ( j = 0 ; j < closed_len; j++ )
    {
      fprintf(stderr, "%lf %lf %lf\n",coord_buffer[j][0],
                                      coord_buffer[j][1],
                                      coord_buffer[j][2]);
    }
    for ( j = closed_len ; j < ring_ptr->len+1; j++ )
    {
      fprintf(stderr, "%lf %lf %lf\n",coord_buffer[0][0],
                                      coord_buffer[0][1],
                                      coord_buffer[0][2]);
    }
#endif

  /* free memory */
  free_d2t(coord_buffer);

  return arc;
}

/*
 * KNTCbridge_close_subchain
 *
 * Closes an arc {r_i,...,r_j} by direct bridging.
 * Simply extracts the subchain [start,end] and
 * stores it in arc.
 *
 * IN:
 *  KNTarc * ring_ptr: ring on which we operate
 *  int start: starting bead of the arc we want to close,
 *  int end:   final bead of the arc we want to close.
 * OUT:
 *  a KNTarc struct with the closed arc stored.
 */
KNTarc  KNTCbridge_close_subchain   ( KNTarc * ring_ptr, int start, int end )
{
  int       j;
  int       closed_len;           /* length of closed ring array */
  int       cls_points = 0;       /* number of closure added points    */

  double    cm[3];                /* center of mass                    */
  double    radius;               /* arc's radius                      */
  double ** coord_buffer;
  KNTarc    arc = KNTarc_DEFAULT;


  /* check ring_ptr correct initialization */
  if( ring_ptr->is_init != 1 || ring_ptr->flag_len != 1 || ring_ptr->coord == NULL )
  {
    failed ( "KNTCbridge_close_subchain. ring_ptr is not correctly initialized!\n");
  }

  /* initialize coord_buffer to store closed arc */
  coord_buffer = d2t(ring_ptr->len + cls_points, 3);
  //arc = KNTinit( );

  /* extract the subchain between start and end, included */
  closed_len = extract_subchain ( ring_ptr->len, ring_ptr->coord, start, end, coord_buffer );
  center_of_mass      ( closed_len, coord_buffer, cm );
  radius = find_radius( closed_len, coord_buffer, cm );

  /* save everything in arc */
  KNTadd_coord ( closed_len, coord_buffer, NULL, &arc );
  KNTarc_SET_value(&arc, arc_type, ARC_ID_ANY, char);
  KNTarc_SET_value(&arc, start, start, int);
  KNTarc_SET_value(&arc, end,   end,   int);
  KNTarc_SET_value(&arc, Rc, radius, double);
  for ( j = 0 ; j < 3 ; j++ )
  {
    arc.cm[j] = cm[j];
  }
  arc.flag_cm = TRUE;
  strncpy(arc.closure,BRIDGECLOSURE,strlen(BRIDGECLOSURE));

  /* free memory */
  free_d2t(coord_buffer);

  return arc;
}
/*
 * uniform_spherical_distribution
 *
 * randomly picks a point on the
 * unitary sphere with uniform probability.
 *
 * ptr_idum is defined in my_random.c
 */
void uniform_spherical_distribution ( double point[3] )
{
  double theta;
  double phi;
  extern long int * ptr_idum;
  theta = acos( 2 * ran2(ptr_idum) - 1 );
  phi   = 2 * PI * ran2 ( ptr_idum );
  point[0] = sin(theta) * cos(phi);
  point[1] = sin(theta) * sin(phi);
  point[2] = cos(theta);
}

void great_circle_path(double A[3], double B[3], double C[3], int n, double **coord_buffer)
{
	int i;
	double v_1[3],v_2[3], v_3[3];
	double prj_AB;
	double theta;
	double dth;
	double R_close;
  extern long int * ptr_idum;
	double phi;
	R_close=dist_d(A,C,3);
	prj_AB = scal_d(A,B,3)/norm_d(B,3);
	//double use of v_1 and v_2
	v_2[0] = B[0];
	v_2[1] = B[1];
	v_2[2] = B[2];
	normalize_d(v_2,3); 
	v_1[0] = A[0] - prj_AB*v_2[0];
	v_1[1] = A[1] - prj_AB*v_2[1];
	v_1[2] = A[2] - prj_AB*v_2[2];
	normalize_d(v_1,3);
	vecprod_d ( v_1, v_2, v_3);
	theta = prj_AB/norm_d(A,3);
	theta = acos ( theta );
	dth = theta / n;
	theta = 0.0;
	coord_buffer[0][0] = B[0] + C[0];
	coord_buffer[0][1] = B[1] + C[1];
	coord_buffer[0][2] = B[2] + C[2];
	for ( i = 1 ; i < n-1; i++ )
	{
		phi = PI/2 - PI/40 + ran2(ptr_idum)*PI/20;
		theta += dth;
		coord_buffer[i][0]= R_close * cos(theta) * sin(phi) * v_2[0] + R_close * sin(theta) * sin(phi) * v_1[0] + R_close * cos(phi) * v_3[0] + C[0];
		coord_buffer[i][1]= R_close * cos(theta) * sin(phi) * v_2[1] + R_close * sin(theta) * sin(phi) * v_1[1] + R_close * cos(phi) * v_3[1] + C[1];
		coord_buffer[i][2]= R_close * cos(theta) * sin(phi) * v_2[2] + R_close * sin(theta) * sin(phi) * v_1[2] + R_close * cos(phi) * v_3[2] + C[2];
	}
	coord_buffer[n-1][0] = A[0] + C[0];
	coord_buffer[n-1][1] = A[1] + C[1];
	coord_buffer[n-1][2] = A[2] + C[2];
}
  /*************************************************************************************
   * extract_subchain
   *
   * Extract a subchain of the chain, from start to end included. Periodic boundary
   * conditions on the chain are assumed (ring).
   *
   * Returns the lenght of the subchain.
   *
   **************************************************************************************/

int  extract_subchain     ( int N,double ** chain, int start, int end,  double ** subchain)
{
  int i;
  int len_subchain;
	if( start <0 || start >= N) {
		failed("In function extract_subchain - KNT_closures.c. Start bead out of boundaries.\n");
	} else if ( end <0 || end >=N) {
		failed("In function extract_subchain - KNT_closures.c. End bead out of boundaries.\n");
	}

  // I want both start and end to be included in the copied
  // subchain. Therefore I add 1 to its length

  if(start < end)
  {
    len_subchain = end - start + 1;
  }
  else
  {
    len_subchain = N - start + end + 1;
  }

  for ( i = 0 ; i < len_subchain ; i++ )
  {
    subchain[i][0] = chain[ ( start + i ) % N ][0];
    subchain[i][1] = chain[ ( start + i ) % N ][1];
    subchain[i][2] = chain[ ( start + i ) % N ][2];
  }

  return len_subchain;
}

/*
 * KNTLreset_random_closure
 *
 * allow the user to reset the default values used in random closures.
 * If negative values are given in input keeps the corresponding
 * default values.
 *
 * Check the beginning of this file for default values.
 */
void KNTLreset_random_closure ( int N_cls, double R_fact, double tresh )
{
  extern int    stch_n_closures ;
  extern double stch_close_fact;
  extern double stch_treshold;

  stch_n_closures = ( N_cls  > 0 ) ? N_cls  : stch_n_closures;
  stch_close_fact = ( R_fact > 0 ) ? R_fact : stch_close_fact;
  stch_treshold   = ( tresh  > 0 ) ? tresh  : stch_treshold ;
}

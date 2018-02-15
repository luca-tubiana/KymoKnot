#include "my_geom.h"

#ifndef	EPSIL
#define EPSIL  0.000000000001 /*0.000001       Machine floating point precision*/
#endif

/************ GEOMETRIC ROUTINES ************/
/*******************************/
void vecprod_d (const double *a, const double *b, double *c)
{

  c[0] = a[1] * b[2] - a[2] * b[1];
  c[1] = a[2] * b[0] - a[0] * b[2];
  c[2] = a[0] * b[1] - a[1] * b[0];
}
/*******************************/

double scal_d (const double * restrict a, const double * restrict b, int dim)
{

  int i;
  double temp;

  temp = 0.0;
  for (i = 0; i < dim; i++)
    {
      temp += a[i] * b[i];
    }
  return (temp);
}
/*******************************/



double norm_d (const double *a, int dim)
{

  return (sqrt (scal_d (a, a, dim)));
}
/*******************************/

/*******************************/
void normalize_d (double *a, int dim)
{
  int i;
  double temp;

  temp = norm_d (a, dim);
  for (i = 0; i < dim; i++)
    {
      a[i] = a[i] / temp;
    }
}



/*******************************/

double dist_d (const double *a, const double *b, int dim)
{

  unsigned short i;
  double temp;

  temp = 0.0;
  for (i = 0; i < 3; i++)
    {
      temp += (a[i] - b[i]) * (a[i] - b[i]);
    }

  temp = sqrt (temp);
  return (temp);
}

double dist_dGEN (const double *a, const double *b, int dim)
{

  unsigned short i;
  double temp;

  temp = 0.0;
  for (i = 0; i < dim; i++)
    {
      temp += (a[i] - b[i]) * (a[i] - b[i]);
    }

  temp = sqrt (temp);
  return (temp);
}

/*******************************/


double dist_segments(const double p0[3], const double p1[3], const double p2[3], const double p3[3]){

  double d02[3],d32[3],d10[3], pa[3], pb[3], mua, mub, min_dist;
  int k;
  double d0232,d3210,d0210,d3232,d1010;

  for(k=0; k < 3; k++){
    d02[k]=p0[k]-p2[k];
    d32[k]=p3[k]-p2[k];
    d10[k]=p1[k]-p0[k];
  }

  d0232=0.0;
  d3210=0.0;
  d0210=0.0;
  d3232=0.0;
  d1010=0.0;

  for(k=0; k < 3; k++){
    d0232+=d02[k]*d32[k];
    d3210+=d32[k]*d10[k];
    d0210+=d02[k]*d10[k];
    d3232+=d32[k]*d32[k];
    d1010+=d10[k]*d10[k];
  }

  mua= (d0232*d3210-d0210*d3232)/(d1010*d3232-d3210*d3210);
  
  mub=(d0232+mua*d3210)/d3232;
  
  if (mua <0) mua=0;
  else if (mua >1) mua=1;
  
  if (mub <0) mub=0;
  else if (mub >1) mub=1;
  
  for(k=0; k < 3; k++){
    pa[k]=p0[k]+mua*(p1[k]-p0[k]);
    pb[k]=p2[k]+mub*(p3[k]-p2[k]);
  }

  min_dist=dist_d(pa,pb,3);

  return(min_dist);
}


/*
     Determine whether or not the line segment p1,p2
     Intersects the 3 vertex facet bounded by pa,pb,pc
     Return true/false and the intersection point p
     The equation of the line is p = p1 + mu (p2 - p1)
     The equation of the plane is a x + b y + c z + d = 0
      n.x x + n.y y + n.z z + d = 0
*/
int LineFacet(const double * restrict p1, const double * restrict p2, const double * restrict pa, const double * restrict pb, const double * restrict pc, double* restrict p){
 /* new version 18/5/2009, CM and LT */
 /* optimized 15/11/2015,  LT */
   double d;
   double bond[3];
   /*double a1,a2,a3;*/
   double denom,mu;
   double n[3];/*pa1[3],pa2[3],pa3[3];*/
   unsigned short k;
   double vp[3], v1[3], v2[3];
	 double r1[3],r2[3];
   double scal_vpv1, scal_v1v1, scal_v2v2, scal_v1v2, scal_vpv2;
   double x,y;
   double EPSIL2; /* tolerance for intersection checks */

   EPSIL2=0.0001; /* higher values make the criterion more stringent (but possibly discard
                     genuinely OK configurations. previously 0.0001*/

   for(k=0; k < 3; k++){
     v1[k]   = pa[k] - pb[k];
     v2[k]   = pc[k] - pb[k];
		 r1[k]   = p1[k] - pb[k];
		 r2[k]   = p2[k] - pb[k];
     bond[k] = p2[k] - p1[k];
   }

 /* Calculate the parameters for the plane */
   n[0] = v1[1]*v2[2] - v1[2]*v2[1];
   n[1] = v1[2]*v2[0] - v1[0]*v2[2];
   n[2] = v1[0]*v2[1] - v1[1]*v2[0];
   //n[0] = (pb[1] - pa[1])*(pc[2] - pa[2]) - (pb[2] - pa[2])*(pc[1] - pa[1]);
   //n[1] = (pb[2] - pa[2])*(pc[0] - pa[0]) - (pb[0] - pa[0])*(pc[2] - pa[2]);
   //n[2] = (pb[0] - pa[0])*(pc[1] - pa[1]) - (pb[1] - pa[1])*(pc[0] - pa[0]);
	 //LET's TRY NOT TO NORMALIZE THINGS!
   //normalize_d(n,3);

	 // IF Both points are above or below the plane, there is no crossing.
	 if ( scal_d(n,r1,3)*scal_d(n,r2,3) > 0 )
	 {
		 return(FALSE);
	 }

   d = - scal_d(n,pa,3);

/* Calculate the position on the line that intersects the plane */
   denom = n[0] * bond[0] + n[1] * bond[1] + n[2] * bond[2];
   if (fabs(denom) < EPSIL){         /* Line and plane don't intersect */
     return(FALSE);
   }

   mu = - (d + scal_d(n,p1,3))/ denom;
	 if (mu < -EPSIL2)
	 {
		 return(FALSE);
	 }
	 else if (mu > (1+EPSIL2))
	 {
		 return(FALSE);
	 }
   //if (mu <  (-EPSIL2) || mu > (1.0 + EPSIL2))   /* Intersection not along line segment */
   //  return(FALSE);

     /* Intersection point */
     for(k=0; k < 3; k++){
       p[k] = p1[k] + mu * bond[k];
       vp[k] = p[k]  - pb[k];
     }

 
     /* Determine whether or not the intersection point is bounded by pa,pb,pc */

   /* we write the location of the intersection point as a linear combination of two
      vectors delimiting the facet. The origin is taken as pb.
      The facet is the locus of points {a*v1+b*v2 | a,b >=0 & a+b <=1}. */

   scal_vpv1 = scal_d(vp,v1,3);  
   scal_vpv2 = scal_d(vp,v2,3);
   scal_v1v2 = scal_d(v1,v2,3);
   scal_v1v1 = scal_d(v1,v1,3);
   scal_v2v2 = scal_d(v2,v2,3);

   denom =  scal_v1v1*scal_v2v2 - scal_v1v2*scal_v1v2; 

   x= ((scal_v2v2)*(scal_vpv1) - (scal_v1v2)*(scal_vpv2))/denom;
   y= -((scal_v1v2)*(scal_vpv1) - (scal_v1v1)*(scal_vpv2))/denom;


   if ((x <  (-EPSIL2) ) || (y <  (-EPSIL2) ))   return(FALSE);
   if ( (x+y) > (1 + EPSIL2))   return(FALSE);

   return(TRUE);
}

int LineFacetOLD(double *p1, double *p2, double *pa, double *pb, double *pc, double *p){
 /* new version 18/5/2009, CM and LT */
   double d;
   /*double a1,a2,a3;*/
   double denom,mu;
   double n[3];/*pa1[3],pa2[3],pa3[3];*/
   int k;
   double vp[3], v1[3], v2[3];
   double scal_vpv1, scal_v1v1, scal_v2v2, scal_v1v2, scal_vpv2;
   double x,y;
   double EPSIL2; /* tolerance for intersection checks */

   EPSIL2=0.0001; /* higher values make the criterion more stringent (but possibly discard
                     genuinely OK configurations. previously 0.0001*/



 /* Calculate the parameters for the plane */
   n[0] = (pb[1] - pa[1])*(pc[2] - pa[2]) - (pb[2] - pa[2])*(pc[1] - pa[1]);
   n[1] = (pb[2] - pa[2])*(pc[0] - pa[0]) - (pb[0] - pa[0])*(pc[2] - pa[2]);
   n[2] = (pb[0] - pa[0])*(pc[1] - pa[1]) - (pb[1] - pa[1])*(pc[0] - pa[0]);
   normalize_d(n,3);
   d = - scal_d(n,pa,3);

/* Calculate the position on the line that intersects the plane */
   denom = n[0] * (p2[0] - p1[0]) + n[1] * (p2[1] - p1[1]) + n[2] * (p2[2] - p1[2]);
   if (fabs(denom) < EPSIL){         /* Line and plane don't intersect */
     return(FALSE);
   }

   mu = - (d + scal_d(n,p1,3))/ denom;


   if (mu <  (-EPSIL2) || mu > (1.0 + EPSIL2))   /* Intersection not along line segment */
     return(FALSE);

     /* Intersection point */
     for(k=0; k < 3; k++){
       p[k] = p1[k] + mu * (p2[k] - p1[k]);
     }

 
     /* Determine whether or not the intersection point is bounded by pa,pb,pc */

   /* we write the location of the intersection point as a linear combination of two
      vectors delimiting the facet. The origin is taken as pb.
      The facet is the locus of points {a*v1+b*v2 | a,b >=0 & a+b <=1}. */

   for(k=0; k < 3; k++){
     vp[k] = p[k]  - pb[k];
     v1[k] = pa[k] - pb[k];
     v2[k] = pc[k] - pb[k];
   }

   scal_vpv1 = scal_d(vp,v1,3);  
   scal_vpv2 = scal_d(vp,v2,3);
   scal_v1v2 = scal_d(v1,v2,3);
   scal_v1v1 = scal_d(v1,v1,3);
   scal_v2v2 = scal_d(v2,v2,3);

   x= ((scal_v2v2)*(scal_vpv1) - (scal_v1v2)*(scal_vpv2))/
      (-((scal_v1v2)*(scal_v1v2)) + (scal_v1v1)*(scal_v2v2));
   y= ((scal_v1v2)*(scal_vpv1) - (scal_v1v1)*(scal_vpv2))/
    ((scal_v1v2)*(scal_v1v2) - (scal_v1v1)*(scal_v2v2));


   if ((x <  (-EPSIL2) ) || (y <  (-EPSIL2) ))   return(FALSE);
   if ( (x+y) > (1 + EPSIL2))   return(FALSE);

   return(TRUE);
}

void center_of_mass(int N, double ** coord, double *cm)
{
  int i;
  cm[0] = cm[1] = cm[2] = 0.0;
  for ( i = 0 ; i < N ; i++ )
  {
    cm[0] += coord[i][0];
    cm[1] += coord[i][1];
    cm[2] += coord[i][2];
  }
  
  cm[0] /= N;
  cm[1] /= N;
  cm[2] /= N;
}

double find_radius ( int N ,double ** coord, double center[3] )
{
  int i;
  double  r, temp_r;
  //The following is to find the farthest vertex from the center of mass (cm),
  // by first computing the cm coordinates, then computing the distances of
  // ALL the vertices to the cm, and finally finding the maximum amongst the
  // distances. To avoid sqrt, which is repeated Len times in each run, it is 
  // better to compute the squared distances then find the maximum amongst them...
  r = 0.0;
  for( i = 0 ; i < N ; i++ )
  {
    temp_r = dist_d( coord[i], center, 3 );
    if (temp_r > r) 
    {
      r = temp_r;
    }		
  }
  // ... However, remember to return the sqrt of the found squared radius
  return r;	
}

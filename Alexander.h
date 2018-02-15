#ifndef HDR_ALX
#define HDR_ALX



/*-------MACROS DEFINITIONS----------*/

#ifdef  min
#undef  min
#endif

#define min( x , y) ( (x) < (y) ? (x) : (y) )

#ifdef  max
#undef  max
#endif

#define max( x , y ) ( (x) > (y) ? (x) : (y) )

#ifdef  sign
#undef  sign
#endif  

#define sign( x ) ( (x) >= 0 ? +1 : -1 )

#define TRUE  1
#define FALSE 0

#define fcirca( x, y, error ) ( fabs( (x) - (y) ) < error ? 1 : 0 )


#define EPSIL2 0.0000001

struct ALX_wspace {
  int        matrix_dim;  // linear dim n of nxn matrix
  int        n_crossing;  // linear dim n of nxn matrix
  int    *   intersec;
  int    **  type;
  int    **  sign;
  int    **  cross; 
  double **  alex_mat;
  double **  x_in;
};

typedef struct ALX_wspace ALX_wspace;

ALX_wspace * ALX_wspace_alloc ( int N );
void ALX_free_wspace ( ALX_wspace * ws );

double  ALX_alex_generict ( int N , double ** prj_chain , int numt, int t[numt], int out_det[numt] ,  ALX_wspace * wspace );
double  ALX_detalex       ( double ** , int );

//double alexander_generict(int lsubc, double vert[lsubc+1][3], int **tipo, 
//    double **xin, int *intersez, int **segno, int **crossing, double **alex,  int numt, double t[numt], double ritorno[numt]);
//double detalex(double **alex,int nnn);


#endif /*ALX_HDR*/

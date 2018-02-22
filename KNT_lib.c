#include "KNT_lib.h"
#include "KNT_qhull.h"
#include "KNT_closures.h"
#include "KNT_table.h"
#include "KNT_simplify.h"
#include "KNT_identify.h"
#include "my_random.h"
#include "my_memory.h"
#include "my_geom.h"
#include "messages.h"

#include "qhull_a.h"

#include <stdio.h>
#include <math.h>   	/* -std=c99 */
#include <stdlib.h>
#include <search.h>  	/* -std=c99 */
#include <gsl/gsl_math.h> //define constants
#include <gsl/gsl_blas.h>

/*
 * Internal functions.
 */
/* comparison functions to be called by qsort and lfind */
int _check_inclusion (int start, int end, int st_p, int end_p);
int _compare_len   	( const void *a , const void *b );
KNTarc * _alloc_KNTarc_array (int array_len, int arc_len, char message[256]);
KNTarc * _create_sorted_KNTarc_array (int *out_array_len, KNTarc *knt_rect,  int unsimp_len, int st_p, int end_p, char message [256]);
/*
 * GLOBAL VARIABLES
 *
 * Defining here the global variables used by the functions keeps
 * them hidden from the final user.
 */
double ** COORD_BUFFER = NULL;

// Used by KNT_matrix. (defined in KNT_closures.c)
extern int      stch_n_closures;      // number of different closure (default)
extern int      stch_is_init; 		    // not inizialized: default values used;
extern double   stch_treshold;        // If less than stch_treshold closed arcs result in the same knot, the topology is left as uncertain

/*------- qhull buffer control ------*/
extern int      qhull_is_init;        /* keep track of qhull_buffer memory state. Use it to avoid memory leaks       */

/*--------KNTarc global variables----*/
extern KNTarc KNTarc_DEFAULT;         /* defined in KNT_arc.c */
/*------KNTid global variables-------*/
extern KNTid KNTid_DEFAULT;

/*
 * KNTLkntmatrix
 *
 * Compute all elements of knot matrix
 * using the closure scheme defined by *close_subchain.
 *
 * IN:
 *  KNTarc * knt_ptr, ring with coordinates etc.
 *  (*close_subchain) closure scheme.
 * OUT:
 *  KNTarc * knt_ptr
 *
 * Last changes: introduced a different loop for type linear. Only
 * half matrix  have to be computed in that case
 */
/*
void KNTLkntmatrix ( KNTarc * knt_ptr, KNTarc (*close_subchain) ( KNTarc *, int, int ), ALX_wspace * alx_wspace )
{
  int i, j, k, l, tmp_k_id, k_id;
  int start, end;
  int k_dets[2];
  int t[2] = {-1,-2};
  int is_random         = FALSE;    // if a random closure scheme is adopted is_random = TRUE
  int determinant       = DONT_CARE;
  int qhull_local_init  = FALSE;
  char str_cls[STR_OUT_MAXLEN] = "Undefined";
  int knot_table [KTABLE_LEN] = KTABLE;
  int knot_dist  [KTABLE_LEN+1];
  int max = 0;
  extern int stch_n_closures;
  extern double stch_treshold;

  KNTarc       arc = KNTarc_DEFAULT;

  //check if structure is correctly initialized

  if( knt_ptr->is_init != 1 || knt_ptr->flag_len != 1 || knt_ptr->coord == NULL )
  {
    failed ( "KNTLkntmatrix_qhull. knt_ptr is not correctly initialized!\n");
  }

  //----------------------------------------------------------------------
  // Set flags according to the closure scheme adopted
  //----------------------------------------------------------------------
  if( close_subchain == &KNTCqhull_close_subchain )
  {
    // if qhull is not initialized, initialize it.
    if(!qhull_is_init)
    {
      qhull_init(knt_ptr->len*3);
      qhull_local_init = TRUE;
    }
    strncpy ( str_cls, QHULLCLOSURE, STR_OUT_MAXLEN );
  }
  else if( close_subchain == &KNTCqhull_hybrid_close_subchain )
  {
    if(!qhull_is_init)
    {
      qhull_init(knt_ptr->len*3);
      qhull_local_init = TRUE;
    }
    strncpy ( str_cls, QHULLCLOSUREHYB, STR_OUT_MAXLEN );
  }
  else if ( close_subchain == &KNTCrandom_close_subchain )
  {
    is_random = TRUE;
    strncpy ( str_cls,STCHCLOSURE, STR_OUT_MAXLEN );
  }
  else if ( close_subchain == &KNTCbridge_close_subchain )
  {
    strncpy ( str_cls,BRIDGECLOSURE,STR_OUT_MAXLEN );
  }
  //-----------------------------------------------------------------------


  //if matrix memory is not inizialized, append it to the structure
  if( knt_ptr->kntmatrix == NULL )
  {
    KNTadd_matrix ( knt_ptr );
  }

  // determine knot_id of  whole chain (see KNT_defaults.h)
  KNTarc_GETif(knt_ptr,Adet_1,k_dets[0],int);
  KNTarc_GETif(knt_ptr,Adet_2,k_dets[1],int);
  if( k_dets[0] == DONT_CARE || k_dets[1] == DONT_CARE )
  {
    determinant = ALX_alex_generict ( knt_ptr->len, knt_ptr->coord, 2, t, k_dets, alx_wspace);
    KNTarc_SET_value(knt_ptr, Adet_1,k_dets[0],int);
    KNTarc_SET_value(knt_ptr, Adet_2,k_dets[1],int);
  }

  k_id = KNTLknot_id( k_dets );

  // Calculate all entries on knot_matrix. i is the beginning of
  // the arc, j its length ( including arc end )
  if(knt_ptr->arc_type == ARC_ID_LIN )
  {
    for ( start = 0 ; start < knt_ptr->len ; start++ )
    {
      for ( end = start + 1 ; end < knt_ptr->len  ; end++ )
      {
        if( end - start < 4 )
        {
          knt_ptr->kntmatrix[start][ end ] = K_Un;
        }
        else if(knt_ptr->kntmatrix[start][ end ] == DONT_CARE)
        {
          if ( is_random == FALSE )
          {
            // close the arc between start and end (included)
            arc = ( *close_subchain ) ( knt_ptr, start, end );
            knt_ptr->kntmatrix[start][ end ] = KNTLknot_determination (&arc,  alx_wspace );
            // free the coordinates inside structure arc
            KNTfree_arc( &arc );
          }
          else
          {
            for ( l = 0 ; l <= KTABLE_LEN ; l++ )
            {
              knot_dist[l] = 0;
            }
            for ( k = 0 ; k < stch_n_closures ; k++ )
            {
              arc = ( *close_subchain ) ( knt_ptr, start, end );
              tmp_k_id = KNTLknot_determination (&arc,  alx_wspace );
              for ( l = 0 ; l < KTABLE_LEN ; l++ )
              {
                if ( tmp_k_id == knot_table[l] )
                {
                  knot_dist[l]++;
                  break;
                }
                 // I add one point to knot_dist, when no known knot
                 // is found, knot_dist last bin is incremented.
                if ( l == ( KTABLE_LEN - 1 ))
                {
                  knot_dist[KTABLE_LEN]++;
                  break;
                }
              }
              KNTfree_arc( &arc );
            }
            max = 0;
            for ( l = 1 ; l <= KTABLE_LEN ; l++ )
            {
              if ( knot_dist[l] > knot_dist[max] )
              {
                max = l ;
              }
            }
            if ( max < KTABLE_LEN && ( (double) knot_dist[max] / stch_n_closures) > stch_treshold )
            {
              knt_ptr->kntmatrix[start][end] = knot_table[max];
            }
            else if ( max == KTABLE_LEN )
            {
              knt_ptr->kntmatrix[start][end] = K_UNKNWN;
            }
            else
            {
               // IMPORTANT: in this case K_UNCRT collect both uncertain
               // topologies and Unknown knots!! This is a problem to be solved!
              knt_ptr->kntmatrix[start][end] = K_UNCRT;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
  }
  else
  {
    for ( i = 0 ; i < knt_ptr->len ; i++ )
    {
      for ( j = 0 ; j < knt_ptr->len ; j++ )
      {
        start = i;
        end   = (i + j) % knt_ptr->len;
        if( j == 0 )
        {
          knt_ptr->kntmatrix[start][ end ] = k_id;
        }
        else if( j>0 && j < 4 )
        {
          knt_ptr->kntmatrix[start][ end ] = K_Un;
        }
        else if(knt_ptr->kntmatrix[start][ end ] == DONT_CARE)
        {
          if ( is_random == FALSE )
          {
            // close the arc between start and end (included)
            arc = ( *close_subchain ) ( knt_ptr, start, end );
            knt_ptr->kntmatrix[start][ end ] = KNTLknot_determination (&arc,  alx_wspace );
            // free the coordinates inside structure arc
            KNTfree_arc( &arc );
          }
          else
          {
            for ( l = 0 ; l <= KTABLE_LEN ; l++ )
            {
              knot_dist[l] = 0;
            }
            for ( k = 0 ; k < stch_n_closures ; k++ )
            {
              arc = ( *close_subchain ) ( knt_ptr, start, end );
              tmp_k_id = KNTLknot_determination (&arc,  alx_wspace );
              for ( l = 0 ; l < KTABLE_LEN ; l++ )
              {
                if ( tmp_k_id == knot_table[l] )
                {
                  knot_dist[l]++;
                  break;
                }
                // I add one point to knot_dist, when no known knot
                // is found, knot_dist last bin is incremented.
                if ( l == ( KTABLE_LEN - 1 ))
                {
                  knot_dist[KTABLE_LEN]++;
                  break;
                }
              }
              KNTfree_arc( &arc );
            }
            max = 0;
            for ( l = 1 ; l <= KTABLE_LEN ; l++ )
            {
              if ( knot_dist[l] > knot_dist[max] )
              {
                max = l ;
              }
            }
            if ( max < KTABLE_LEN && ( (double) knot_dist[max] / stch_n_closures) > stch_treshold )
            {
              knt_ptr->kntmatrix[start][end] = knot_table[max];
            }
            else if ( max == KTABLE_LEN )
            {
              knt_ptr->kntmatrix[start][end] = K_UNKNWN;
            }
            else
            {
               // IMPORTANT: in this case K_UNCRT collect both uncertain
               // topologies and Unknown knots!! This is a problem to be solved!
              knt_ptr->kntmatrix[start][end] = K_UNCRT;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
  }
  // set closure type identifier
  strncpy(knt_ptr->closure,str_cls,strlen(str_cls));

  // free memory

  if(qhull_local_init)
  {
    qhull_terminate();
    qhull_is_init = 0;
  }
  else
  {
    qhull_free_mem();
  }
}
*/

void KNTL_TDloc_rect1 ( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws )
{
  int        i, j, k, l;
  int        start, end, klen, knot_len;
  int        r_start, r_end;
	int				 k_id;
	KNTid      KID, arc_KID, cmp_arc_KID;
  int        _continue_       = FALSE;
  int        qhull_local_init = FALSE;
  char       str_cls[STR_OUT_MAXLEN] = "Undefined";
  char       fail_str[128];
  KNTarc     arc = KNTarc_DEFAULT;
  KNTarc     cmp_arc = KNTarc_DEFAULT;    /* arc and complementar arc */
  KNTarc       tmp     = KNTarc_DEFAULT;
  KNTarc     *  knt_end;
  short      ** f_matrix;
  int        arcs_array_len;
  KNTarc     * arcs_array;

  /*-----STARTING  routine checks ----------------------------------*/
  /*check if structure is correctly initialized */

  if( knt_ptr->is_init != 1 || knt_ptr->flag_len != 1 || knt_ptr->coord == NULL )
  {
    failed ( "KNTLloc_shrtcnt_knot. knt_ptr is not correctly initialized!\n");
  }
  if( knt_rect->is_init != 1 || knt_rect->flag_len != 1 || knt_rect->coord == NULL )
  {
    failed ( "KNTLloc_shrtcnt_knot. knt_rect is not correctly initialized!\n");
  }
  /* check closure and inizialize qhull if needed */
  if ( close_subchain == &KNTCqhull_hybrid_close_subchain  )
  {
    /*
     * if qhull is not initialized, initialize it.
     */
    if(!qhull_is_init)
    {
      qhull_init(knt_rect->len*3);
      qhull_local_init = TRUE;
    }
    strncpy ( str_cls,QHULLCLOSUREHYB, STR_OUT_MAXLEN);
  }
  /*if matrix memory is not inizialized, append it to the structure */
  if( knt_ptr->kntmatrix == NULL ) { KNTadd_matrix ( knt_ptr ); }
  /* determine knot_id of  whole chain (see KNT_defaults.h) */
  if ( st_p != DONT_CARE && end_p != DONT_CARE )
  {
    tmp = ( *close_subchain )( knt_ptr , knt_rect->index[st_p], knt_rect->index[end_p] );
    KID=KNTID_identify_knot (&tmp,ws);
    KNTfree_arc ( &tmp );
  }
  else
  {
    KID=KNTID_identify_knot (knt_ptr,ws);
  }
	//set target knot for search.
  if (KID.k_id==K_UNKNWN) { KID.k_id = K_UNKNWN_B; }
  KNTID_set_target_knot(ws,KID);
  k_id=KID.k_id;
	//This MUST be changed into something more reliable (error code perhaphs?)
  if ( k_id == K_Un )
  {
    fprintf(stderr,"WARNING!\n In KNTLloc_shrt_knot_rect1 \n No knot is present between beads %d and %d on knt_rect\n",
        knt_rect->index[st_p], knt_rect->index[end_p]);
    return;
  }
  /*-----END of initialization routine checks ----------------------*/
  /* --- define an array of arcs ---- */

  arcs_array_len = knt_rect->len * knt_rect->len;
	arcs_array = _alloc_KNTarc_array (arcs_array_len, knt_ptr->len, "In function KNTL_TDloc_rect1");
  /*arcs_array = ( KNTarc * ) calloc ( arcs_array_len, sizeof( KNTarc_DEFAULT ));
  if (arcs_array == NULL )
  {
    sprintf(fail_str,"\nfailed to alloc arcs_array\n in KNTLloc_shrtcnt_knot_rect2.\n array size: %d\n",arcs_array_len);
    failed(fail_str);
  }
  for ( k = 0 ; k < arcs_array_len ; k++ )
  {
    arcs_array[k] = KNTarc_DEFAULT;
    arcs_array[k].len = knt_ptr->len;
  }
	*/

  /*
   * Initialize f_matrix f = 1, 0, -1.
   * Initialize diagonal elements of knot_matrix.
   */
  f_matrix = s2t(knt_rect->len, knt_rect->len);
	int wlen;
	int lst_p;
	int I;
	if(st_p!=DONT_CARE && end_p !=DONT_CARE)
	{
		wlen = (end_p > st_p) ?  end_p - st_p : end_p + knt_rect->len - st_p;
		lst_p=st_p;
		for ( i = 0 ; i < knt_rect->len; i++ )
		{
			for(j=knt_rect->len-1;j>0;j--)
			{
				f_matrix[i][j]=-1;
			}
		}
		f_matrix[lst_p][wlen]=1;
	}
	else
	{
		lst_p=0;
		wlen=knt_rect->len-1;
		for ( i = 0 ; i < knt_rect->len; i++ )
		{
			f_matrix[i][wlen]=1;
			for(j=wlen-1;j>0;j--)
			{
				f_matrix[i][j]=-1;
			}
		}
	}
  k=0;
  for ( j = wlen ; j > 3 ; j-- )
  {
    _continue_ = FALSE;
		for ( i = 0 ; i <= wlen ; i++ )
    {
      /*
       * The following condition guarantees that there exists an uninterrupted
			 * path of knotted arcs, starting from st_p,st_p+wlen. When st_p and
			 * end_p are not specified, we have a family of paths.
       *
       * C arrays begin with 0. So the element of matrix [i][j] refers to the
       * arc starting in i of length j+1 ( including start and end ).
       */
			I=(lst_p+i)%knt_rect->len;
      if( (f_matrix[I][ j ] == TRUE ) || (f_matrix[ ( I - 1 + knt_rect->len )%knt_rect->len][j] == TRUE ) )
      {
        start = I;
        end   = ( I + j ) % knt_rect->len;
				r_start=knt_rect->index[start];
				r_end=knt_rect->index[end];
        /*
         * check the matrix to see if the topology of the two arcs
         * has already been determined. If not do it.
         */
        if(knt_ptr->kntmatrix[r_start][r_end] == DONT_CARE)
				{
					arc = ( *close_subchain )( knt_ptr , r_start, r_end );
					arc_KID=KNTID_identify_knot(&arc,ws);
					knt_ptr->kntmatrix[r_start][r_end] = arc_KID.k_id;;
				}
				else if (knt_ptr->kntmatrix[r_start][r_end]==k_id)
				{
					arc_KID=KID;
				}
        if(knt_ptr->kntmatrix[r_end][r_start] == DONT_CARE)
        {
          if ( (knt_rect->len - j)  < 4 ) // no knots possible
          {
            knt_ptr->kntmatrix[r_end][r_start] = K_Un;
          }
          else
          {
            cmp_arc 		= ( *close_subchain )( knt_ptr , r_end, r_start );
						cmp_arc_KID =	KNTID_identify_knot(&cmp_arc,ws);
            knt_ptr->kntmatrix[r_end][r_start] = cmp_arc_KID.k_id;
          }
        }
        if(knt_ptr->kntmatrix[r_start][r_end] == k_id && knt_ptr->kntmatrix[r_end][r_start] == K_Un )
        {
					arcs_array[k].len 	= (r_end > r_start)? r_end - r_start : r_end + knt_ptr->len -r_start;
          arcs_array[k].start = start;
          arcs_array[k].end   = end;
					KNTarc_SET_value(&arcs_array[k], knot_type,arc_KID,KNTid); // I have to improve this!!! 
          k++;
          f_matrix[I][j-1] = TRUE;
          _continue_     = TRUE;
					//MAH!
          //if ( start == st_p && end == end_p )
          //{
          //  _continue_ = FALSE;
          //}
        }
        else
        {
          f_matrix[I][j-1] = FALSE;
        }
      }
      /* free coordinates in arc and cmp_arc */
      KNTfree_arc ( &arc     );
      KNTfree_arc ( &cmp_arc );
      /* reset arc and cmp_arc */
      KNTreset    ( &arc     );
      KNTreset    ( &cmp_arc );
    }
    if ( !_continue_ )
    {
      break;
    }
  }

   // Since the default length is knt_ptr->length,we can sort the whole array.
  //qsort ( arcs_array, arcs_array_len , sizeof(arcs_array[0]),_compare_len);
  qsort ( arcs_array, k , sizeof(arcs_array[0]),_compare_len);
	knot_len=knt_ptr->len;
	for(i=0;i<k;i++)
	{
		if ( st_p != DONT_CARE && end_p != DONT_CARE)
		{
			if( _check_inclusion(arcs_array[i].start, arcs_array[i].end, st_p, end_p) == FALSE)
			{
				continue;
			}
		}

		klen = arcs_array[i].len;

#if DEBUG == 2
		fprintf(stderr,"array length: %d\n",k);
		fprintf (stderr,"start %d end %d len %d\n",arcs_array[i].start, arcs_array[i].end,arcs_array[i].len);
		fprintf (stderr,"start %d end %d len %d\n",arcs_array[k-1].start, arcs_array[k-1].end,arcs_array[k-1].len);
		for ( j = knt_rect->len - 1 ; j > 0 ; j-- )
		{
			for ( l = 0 ; l < knt_rect->len; l++ )
			{
				fprintf(stderr,"%4d %4d %2d\n ",l,j,f_matrix[l][j]);
			}
		}
#endif

		//Save ALL knotted arcs with corresponding to the minimal knot length
		if(klen<=knot_len)
		{
			knot_len=klen;
			/*copy everything on knt_end */
			r_start		= knt_rect->index[arcs_array[i].start];
			r_end			= knt_rect->index[arcs_array[i].end];
			arcs_array[i].start=r_start;
			arcs_array[i].end=r_end;
			knt_end = KNTpush ( knt_ptr, &(arcs_array[i]));
			KNTarc_SET_value(knt_end, arc_type, ARC_ID_SCK, char);
			//2CHECK
			//KNTarc_SET_value(knt_end, knot_type,arcs_array[i].knot_type,KNTid); // I have to improve this!!! 
			KNTarc_SET_value(knt_end, knot_type,arcs_array[i].knot_type,KNTid); // I have to improve this!!! 
			strncpy(knt_end->closure,str_cls,strlen(str_cls));
			strncpy(knt_end->simplification,SIMPTOPO,strlen(SIMPRECT));
		}
		else{
			break;
		}
	}

  free_s2t ( f_matrix );
  free ( arcs_array );

  if(qhull_local_init)
  {
    qhull_terminate();
    qhull_is_init = 0;
  }
  else
  {
    qhull_free_mem();
  }

}

void KNTL_BUloc_rect1 ( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws )
{
  int          i, j, k,  start, end,arclen,len;
	int 				k_id;
  KNTid 			KID, arc_KID,cmp_arc_KID; //knot identification
  int          qhull_local_init = FALSE;
  char         str_cls[STR_OUT_MAXLEN] = "Undefined";
  char         fail_str[128];
  //int          last_cycle = FALSE;
  KNTarc     * knt_end;
  KNTarc       arc     = KNTarc_DEFAULT;
  KNTarc       cmp_arc = KNTarc_DEFAULT;
  KNTarc       tmp     = KNTarc_DEFAULT;
  /* used in the FY shuffle */
  extern long int * ptr_idum;
  /*
   * I use this to perform a sorting of arcs with qsort
   */
  int          arcs_array_len;
  KNTarc     * arcs_array;
	int r_start, r_end;
	int one_knot_found;
	int knot_len;

  /*-----STARTING  routine checks ----------------------------------*/
  /*check if structure is correctly initialized */

  if( knt_ptr->is_init != 1 || knt_ptr->flag_len != 1 || knt_ptr->coord == NULL )
  {
    failed ( "KNTLloc_shrt_knot_rect. knt_ptr is not correctly initialized!\n");
  }
  if( knt_rect->is_init != 1 || knt_rect->flag_len != 1 || knt_rect->coord == NULL )
  {
    failed ( "KNTLloc_shrt_knot_rect. knt_rect is not correctly initialized!\n");
  }
  if ( close_subchain == &KNTCqhull_hybrid_close_subchain )
  {
    /*
     * if qhull is not initialized, initialize it.
     */
    if(!qhull_is_init)
    {
      qhull_init(knt_rect->len*3);
      qhull_local_init = TRUE;
    }
    strncpy ( str_cls,QHULLCLOSUREHYB, STR_OUT_MAXLEN);
  }
  //if knt_ptr->kntmatrix memory is not inizialized, append it to the structure
  if( knt_ptr->kntmatrix == NULL ) { KNTadd_matrix ( knt_ptr ); }
  // determine knot_id of  whole chain (see KNT_defaults.h)
  if ( st_p != DONT_CARE && end_p != DONT_CARE )
  {
    tmp = ( *close_subchain )( knt_ptr , knt_rect->index[st_p], knt_rect->index[end_p] );
    KID=KNTID_identify_knot (&tmp,ws);
    KNTfree_arc ( &tmp );
  }
  else
  {
    KID=KNTID_identify_knot (knt_ptr,ws);
  }
  if (KID.k_id==K_UNKNWN) { KID.k_id = K_UNKNWN_B; }
  KNTID_set_target_knot(ws,KID);
  k_id=KID.k_id;
  if ( k_id == K_Un )
  {
    fprintf(stderr,"WARNING!\n In KNTLloc_shrt_knot_rect1 \n No knot is present between beads %d and %d on knt_rect\n",
        knt_rect->index[st_p], knt_rect->index[end_p]);
    return;
  }
  /*-----END of initialization routine checks ----------------------*/
  /*----generate sorted array of arcs ------------------------------*/
	//This can easily be a function in itself
  // Qsort reorders the array and gives as  a result an array of
  // simplified arcs ordered according to their corresponding length
  // on the original ring, from smaller to bigger length
	
	arcs_array = _create_sorted_KNTarc_array (&k, knt_rect,knt_ptr->len,st_p,end_p,"In function KNTL_BUloc_rect1");
	/*
  arcs_array_len = knt_rect->len * knt_rect->len;
  arcs_array = ( KNTarc * ) calloc ( arcs_array_len, sizeof( KNTarc_DEFAULT ));
  if (arcs_array == NULL )
  {
    sprintf(fail_str,"\nfailed to alloc arcs_array\n in KNTLloc_shrt_knot_rect1.\n array size: %d\n",arcs_array_len);
    failed(fail_str);
  }
  k=0;
  for ( i = 0 ; i < knt_rect->len; i++ )
  {
    for ( j = 0 ; j < knt_rect->len ; j++ )
    {
      start = knt_rect->index[i];
      end   = knt_rect->index[j];
      arcs_array[k] = KNTarc_DEFAULT;
      arcs_array[k].start = i;
      arcs_array[k].end   = j;
      if ( st_p < 0 || end_p < 0 )
      {
         arcs_array[k].len   = ( end > start ) ? end - start : end + knt_ptr->len - start ;
      }
      else if ( st_p < end_p && i >= st_p && j<= end_p && i < j)
      {
        arcs_array[k].len   = ( end > start ) ? end - start : end + knt_ptr->len - start ;
      }
      else if ( st_p >= end_p && !( ( i > end_p && i < st_p) || (  j > end_p &&  j < st_p) || ( i == end_p &&  j == st_p )) )
      {
        arcs_array[k].len   = ( end > start ) ? end - start : end + knt_ptr->len - start ;
      }
      else
      {
        arcs_array[k].len =  knt_ptr->len;
      }
      k++;
    }
  }
  qsort ( arcs_array,k, sizeof(arcs_array[0]),_compare_len);
	*/

	one_knot_found=0;
	knot_len=knt_ptr->len;
  for ( i = 0 ; i < k ; i++ )
  {
    start  = arcs_array[i].start;
    end    = arcs_array[i].end;
    len    = arcs_array[i].len;
    arclen = ( end > start) ? end - start : end + knt_rect->len - start;

		r_start= knt_rect->index[start];
		r_end	 = knt_rect->index[end];

		//questo dovrebbe salvare la degenerazione.
		if (one_knot_found && len > knot_len)
		{
			KNTfree_arc ( &arc );
			KNTfree_arc ( &cmp_arc );
			break;
		}
		//
    if(arclen < 4 )
    {
      continue;
    }
    /* set arc and cmp_arc to default knot as a safety measure */
    arc     = KNTarc_DEFAULT;
    cmp_arc = KNTarc_DEFAULT;
    /* primary arc */
    if ( knt_ptr->kntmatrix[r_start][r_end] == DONT_CARE )
    {
      if ( len < 4 || arclen < 4 )
      {
        knt_ptr->kntmatrix[r_start][r_end] = K_Un;
      }
      else if ( arclen == knt_rect->len )
      {
        knt_ptr->kntmatrix[r_start][r_end] = k_id;
				arc_KID=KID;
      }
      else
      {
        arc = ( *close_subchain )( knt_ptr , r_start, r_end );
				arc_KID=KNTID_identify_knot(&arc,ws);
        knt_ptr->kntmatrix[r_start][r_end] = arc_KID.k_id;;
        //knt_ptr->kntmatrix[r_start][r_end] = KNTLknot_determination ( &arc, alx_wspace );
      }
    }
		else if (knt_ptr->kntmatrix[r_start][r_end]==k_id)
		{
				arc_KID=KID;
		}
    /* complementar arc */
    if( knt_ptr->kntmatrix[r_start][r_end] == k_id && knt_ptr->kntmatrix[r_end][r_start] == DONT_CARE)
    {
      if( knt_rect->len - arclen < 4  )
      {
        knt_ptr->kntmatrix[r_end][r_start] = K_Un;
      }
      else
      {
        cmp_arc = ( *close_subchain )( knt_ptr , r_end, r_start );
				cmp_arc_KID=KNTID_identify_knot (&cmp_arc,ws);
        knt_ptr->kntmatrix[r_end][r_start] = cmp_arc_KID.k_id;
        //knt_ptr->kntmatrix[r_end][r_start] = KNTLknot_determination ( &cmp_arc, alx_wspace );
      }
    }
    /* check if arc is knotted */
    if(knt_ptr->kntmatrix[r_start][r_end] == k_id && knt_ptr->kntmatrix[r_end][r_start] == K_Un )
		{
			tmp = ( *close_subchain )( knt_ptr, r_start, r_end );
			knt_end = KNTpush ( knt_ptr, &tmp);
			KNTfree_arc(&tmp);
			/* I do not want to pass coordinates */
			free_d2t(knt_end->coord);
			knt_end->coord = NULL;
			KNTarc_SET_value(knt_end, arc_type, ARC_ID_SK, char);
	    KNTarc_SET_value(knt_end, knot_type,arc_KID,KNTid);
			/*--*/
			//KNTarc_SET_value(knt_end, len,len,int);
			strncpy(knt_end->closure,str_cls,strlen(str_cls));
			strncpy(knt_end->simplification,SIMPRECT,strlen(SIMPRECT));
			one_knot_found=1;
			knot_len=len;

		}
    /* free coordinates in arc and cmp_arc */
    KNTfree_arc ( &arc );
    KNTfree_arc ( &cmp_arc );
    /* reset arc and cmp_arc */
    KNTreset    ( &arc     );
    KNTreset    ( &cmp_arc );
  }

  free ( arcs_array );
  if(qhull_local_init)
  {
    qhull_terminate();
    qhull_is_init = 0;
  }
  else
  {
    qhull_free_mem();
  }
}

void KNTL_UNSloc_rect1 ( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p, KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws )
{
  int          i, j, k,  start, end,arclen,len;
  int          k_id;
  KNTid 			KID, arc_KID; //knot identification
  int          qhull_local_init = FALSE;
  char         str_cls[STR_OUT_MAXLEN] = "Undefined";
  char         fail_str[128];
  //int          last_cycle = FALSE;
  KNTarc     * knt_end;
  KNTarc       arc     = KNTarc_DEFAULT;
  KNTarc       cmp_arc = KNTarc_DEFAULT;
  KNTarc       tmp     = KNTarc_DEFAULT;
  /* used in the FY shuffle */
  extern long int * ptr_idum;
  /*
   * I use this to perform a sorting of arcs with qsort
   */
  int          arcs_array_len;
  KNTarc     * arcs_array;
	int r_start, r_end;
	int one_knot_found;
	int knot_len;

  /*-----STARTING  routine checks ----------------------------------*/
  /*check if structure is correctly initialized */

  if( knt_ptr->is_init != 1 || knt_ptr->flag_len != 1 || knt_ptr->coord == NULL )
  {
    failed ( "KNTLloc_shrt_knot_rect. knt_ptr is not correctly initialized!\n");
  }
  if( knt_rect->is_init != 1 || knt_rect->flag_len != 1 || knt_rect->coord == NULL )
  {
    failed ( "KNTLloc_shrt_knot_rect. knt_rect is not correctly initialized!\n");
  }

  if ( close_subchain == &KNTCqhull_hybrid_close_subchain )
  {
    /*
     * if qhull is not initialized, initialize it.
     */
    if(!qhull_is_init)
    {
      qhull_init(knt_rect->len*3);
      qhull_local_init = TRUE;
    }
    strncpy ( str_cls,QHULLCLOSUREHYB, STR_OUT_MAXLEN);
  }
  /*if knt_ptr->kntmatrix memory is not inizialized, append it to the structure */
  if( knt_ptr->kntmatrix == NULL )
  {
    KNTadd_matrix ( knt_ptr );
  }
  /* determine knot_id of  whole chain (see KNT_defaults.h) */
	//This must be done on the unsimplified chain!!!
  if ( st_p != DONT_CARE && end_p != DONT_CARE )
  {
    tmp = ( *close_subchain )( knt_ptr , knt_rect->index[st_p], knt_rect->index[end_p] );
    KID=KNTID_identify_knot (&tmp,ws);
    KNTfree_arc ( &tmp );
  }
  else
  {
    KID=KNTID_identify_knot (knt_ptr,ws);
  }
  if (KID.k_id==K_UNKNWN) { KID.k_id = K_UNKNWN_B; }
  KNTID_set_target_knot(ws,KID);
  k_id=KID.k_id;
  if ( k_id == K_Un )
  {
    fprintf(stderr,"WARNING!\n In KNTL_UNSloc_rect1 \n No knot is present between beads %d and %d on knt_rect\n",
        knt_rect->index[st_p], knt_rect->index[end_p]);
    return;
  }
  /*-----END of initialization routine checks ----------------------*/
  /*----generate sorted array of arcs ------------------------------*/
	//This can easily be a function in itself
	//int (KNTarc *sorted_arcs_array, KNTarc *knt_rect, int st_p, int end_p);
	arcs_array = _create_sorted_KNTarc_array (&k, knt_rect,knt_ptr->len,st_p,end_p,"In function KNTL_BUloc_rect1");
	/*
  arcs_array_len = knt_rect->len * knt_rect->len;
  arcs_array = ( KNTarc * ) calloc ( arcs_array_len, sizeof( KNTarc_DEFAULT ));
  if (arcs_array == NULL )
  {
    sprintf(fail_str,"\nfailed to alloc arcs_array\n in KNTLloc_shrt_knot_rect1.\n array size: %d\n",arcs_array_len);
    failed(fail_str);
  }
  k=0;
  for ( i = 0 ; i < knt_rect->len; i++ )
  {
    for ( j = 0 ; j < knt_rect->len ; j++ )
    {
      start = knt_rect->index[i];
      end   = knt_rect->index[j];
      arcs_array[k] = KNTarc_DEFAULT;
      arcs_array[k].start = i;
      arcs_array[k].end   = j;
      if ( st_p < 0 || end_p < 0 )
      {
         arcs_array[k].len   = ( end > start ) ? end - start : end + knt_ptr->len - start ;
      }
      else if ( st_p < end_p && i >= st_p && j<= end_p && i < j)
      {
        arcs_array[k].len   = ( end > start ) ? end - start : end + knt_ptr->len - start ;
      }
      else if ( st_p >= end_p && !( ( i > end_p && i < st_p) || (  j > end_p &&  j < st_p) || ( i == end_p &&  j == st_p )) )
      {
        arcs_array[k].len   = ( end > start ) ? end - start : end + knt_ptr->len - start ;
      }
      else
      {
        arcs_array[k].len =  knt_ptr->len;
      }
      k++;
    }
  }
  qsort ( arcs_array,k, sizeof(arcs_array[0]),_compare_len);
	*/

	one_knot_found=0;
	knot_len=knt_ptr->len;
  for ( i = 0 ; i < k ; i++ )
  {
    start  = arcs_array[i].start;
    end    = arcs_array[i].end;
    len    = arcs_array[i].len;
    arclen = ( end > start) ? end - start : end + knt_rect->len - start;

		r_start= knt_rect->index[start];
		r_end	 = knt_rect->index[end];

		//questo dovrebbe salvare la degenerazione.
		if (one_knot_found && len > knot_len)
		{
			KNTfree_arc ( &arc );
			KNTfree_arc ( &cmp_arc );
			break;
		}
		//
    if(arclen < 4 )
    {
      continue;
    }
    /* set arc and cmp_arc to default knot as a safety measure */
    arc     = KNTarc_DEFAULT;
    cmp_arc = KNTarc_DEFAULT;
    /* primary arc */
    if ( knt_ptr->kntmatrix[r_start][r_end] == DONT_CARE )
    {
      if ( len < 4 || arclen < 4 )
      {
        knt_ptr->kntmatrix[r_start][r_end] = K_Un;
      }
      else if ( arclen == knt_rect->len )
      {
        knt_ptr->kntmatrix[r_start][r_end] = k_id;
      }
      else
      {
        arc = ( *close_subchain )( knt_ptr , r_start, r_end );
				arc_KID=KNTID_identify_knot(&arc,ws);
        knt_ptr->kntmatrix[r_start][r_end] = arc_KID.k_id;;
      }
    }
    // check if arc is knotted
    if(knt_ptr->kntmatrix[r_start][r_end] == k_id)
		{
			tmp = ( *close_subchain )( knt_ptr, r_start, r_end );
			knt_end = KNTpush ( knt_ptr, &tmp);
			KNTfree_arc(&tmp);
			// We do not want to pass coordinates
			free_d2t(knt_end->coord);
			knt_end->coord = NULL;
			KNTarc_SET_value(knt_end, arc_type, ARC_ID_SKU, char);
			KNTarc_SET_value(knt_end, knot_type,knt_ptr->knot_type,KNTid);
			/*--*/
			//KNTarc_SET_value(knt_end, len,len,int);
			strncpy(knt_end->closure,str_cls,strlen(str_cls));
			strncpy(knt_end->simplification,SIMPRECT,strlen(SIMPRECT));
			one_knot_found=1;
			knot_len=len;
		}
    // free coordinates in arc and cmp_arc
    KNTfree_arc ( &arc );
    KNTfree_arc ( &cmp_arc );
    // reset arc and cmp_arc
    KNTreset    ( &arc     );
    KNTreset    ( &cmp_arc );
  }

  free ( arcs_array );
  if(qhull_local_init)
  {
    qhull_terminate();
    qhull_is_init = 0;
  }
  else
  {
    qhull_free_mem();
  }
}

/*
 * Auxiliary functions
 */


void buffer_init ( double *** buff,int buffer_dim)
{
  if( *buff == NULL )
  {
    *buff = d2t(buffer_dim,3);
  }
}
void free_buffer ( double *** buff )
{
  if ( *buff != NULL )
  {
    free_d2t ( *buff  );
    *buff = NULL;
  }
}




int _compare_len( const void *a , const void *b )
{
  const KNTarc * ia = (const KNTarc * ) a;
  const KNTarc * ib = (const KNTarc * ) b;
  return ia->len - ib->len;
}

/*
 * Check if the arc give by start,end is included in the
 * arc given by st_p, end_p.
 */
int _check_inclusion ( int start, int end, int st_p, int end_p )
{
  if (st_p < end_p )
  {
    if ( start <= end && start >=st_p && end <=end_p) {return TRUE;}
    else { return FALSE;}
  }
  else if (st_p > end_p )
  {
    if ( start<=end && end<=end_p) { return TRUE;}
    else if ( start > end && start>=st_p && end<=end_p) {return TRUE;}
    else {return FALSE;}
  }
  else
  {
    return FALSE;
  }
  failed("unrecognized condition in check_inclusione..\n");
}


KNTarc * _alloc_KNTarc_array (int array_len, int arc_len, char message[512])
{
	char fail_str[1024];
	KNTarc * arcs_array = ( KNTarc * ) calloc ( array_len, sizeof( KNTarc_DEFAULT ));
  if (arcs_array == NULL )
  {
    sprintf(fail_str,"\nFailed to alloc arcs_array of size: %d.\n%s\n",array_len,message);
    failed(fail_str);
  }
  for ( int k = 0 ; k < array_len ; k++ )
  {
    arcs_array[k] = KNTarc_DEFAULT;
    arcs_array[k].len = arc_len;
  }
	return arcs_array;
}

/*
 * Auxiliary function used by BUloc_rect1 and UNSloc_rect1. st_p and end_p are 
 * on the rectified chain. unsimp_len is the length of the unsimplified ring.
 */
KNTarc * _create_sorted_KNTarc_array (int *out_array_len, KNTarc *knt_rect,  int unsimp_len, int st_p, int end_p, char message [256])
{
	char fail_str[512];
	*out_array_len=knt_rect->len*knt_rect->len;
	sprintf(fail_str,"%s\nIn function _create_sorted_KNTarc_array.\n",message);
	KNTarc * arcs_array = _alloc_KNTarc_array (*out_array_len,unsimp_len, fail_str); 
  int k=0;
	int start,end;
  for ( int i = 0 ; i < knt_rect->len; i++ )
  {
    for ( int j = 0 ; j < knt_rect->len ; j++ )
    {
      start = knt_rect->index[i];
      end   = knt_rect->index[j];
      arcs_array[k] = KNTarc_DEFAULT;
      arcs_array[k].start = i;
      arcs_array[k].end   = j;
      if ( st_p < 0 || end_p < 0 )
      {
         arcs_array[k].len   = ( end > start ) ? end - start : end + unsimp_len - start ;
      }
      else if ( st_p < end_p && i >= st_p && j<= end_p && i < j)
      {
        arcs_array[k].len   = ( end > start ) ? end - start : end + unsimp_len - start ;
      }
      else if ( st_p >= end_p && !( ( i > end_p && i < st_p) || (  j > end_p &&  j < st_p) || ( i == end_p &&  j == st_p )) )
      {
        arcs_array[k].len   = ( end > start ) ? end - start : end + unsimp_len - start ;
      }
      else
      {
        arcs_array[k].len =  unsimp_len;
      }
      k++;
    }
  }
  qsort ( arcs_array,k, sizeof(arcs_array[0]),_compare_len);
	return arcs_array;
}

void KNTLrotate ( KNTarc * knt_ptr, double axis[3], double theta)
{
  int i;
  double CsTh, SnTh,OnemCsTh;
  double nx,ny,nz;
  gsl_vector *v = gsl_vector_alloc (3);
  gsl_vector *w = gsl_vector_alloc (3);
  gsl_matrix *R = gsl_matrix_alloc(3,3);

  if ( knt_ptr == NULL )
  {
    failed("tryng to rotate a NULL knt_struct!\n");
  }
  if ( knt_ptr->is_init == FALSE )
  {
    failed("tryng to rotate a non initialized knt_struct!\n");
  }
  if ( knt_ptr->coord == NULL )
  {
    failed("tryng to rotate an empty knt_struct!\n");
  }

  normalize_d(axis,3);
  nx = axis[0]; ny = axis[1]; nz = axis[2]; // I know it is dumb, just reusing code..
  CsTh = cos(theta);
  SnTh = sin(theta);
  OnemCsTh = 1 - CsTh;
  //random versor for PIVOT rotation |n| = 1
  //rotation matrix, from quaternions multiplication
  //first row
  gsl_matrix_set ( R,0,0,CsTh + nx*nx* OnemCsTh);
  gsl_matrix_set ( R,0,1,nx*ny*OnemCsTh - nz*SnTh);
  gsl_matrix_set ( R,0,2,nx*nz*OnemCsTh + ny*SnTh);
  //second row
  gsl_matrix_set ( R,1,0,nx*ny*OnemCsTh +nz*SnTh);
  gsl_matrix_set ( R,1,1,CsTh + ny*ny*OnemCsTh);
  gsl_matrix_set ( R,1,2,ny*nz*OnemCsTh - nx*SnTh);
  //third row
  gsl_matrix_set ( R,2,0,nx*nz*OnemCsTh - ny*SnTh);
  gsl_matrix_set ( R,2,1,ny*nz*OnemCsTh + nx*SnTh);
  gsl_matrix_set ( R,2,2,CsTh + nz*nz*OnemCsTh);
  for ( i = knt_ptr->len-1; i >=0 ; i-- )
  {
    knt_ptr->coord[i][0] -=knt_ptr->coord[0][0];
    knt_ptr->coord[i][1] -=knt_ptr->coord[0][1];
    knt_ptr->coord[i][2] -=knt_ptr->coord[0][2];
  }
  for ( i = knt_ptr->len-1; i >0 ; i-- )
  {
    gsl_vector_set ( v, 0, knt_ptr->coord[i][0] - knt_ptr->coord[0][0]);
    gsl_vector_set ( v, 1, knt_ptr->coord[i][1] - knt_ptr->coord[0][1]);
    gsl_vector_set ( v, 2, knt_ptr->coord[i][2] - knt_ptr->coord[0][2]);
    gsl_blas_dgemv ( CblasNoTrans, 1, R, v, 0,w);

    knt_ptr->coord[i][0] = gsl_vector_get(w,0);
    knt_ptr->coord[i][1] = gsl_vector_get(w,1);
    knt_ptr->coord[i][2] = gsl_vector_get(w,2);
  }
	gsl_matrix_free(R);
	gsl_vector_free(v);
	gsl_vector_free(w);
}

void KNTLrotate_random ( KNTarc * knt_ptr )
{
	double s;
	double V1;
	double V2;
	double dR;
	double axis[3];
	double theta;
  extern long int     * ptr_idum;
  if ( knt_ptr == NULL )
  {
    failed("tryng to rotate a NULL knt_struct!\n");
  }
  if ( knt_ptr->is_init == FALSE )
  {
    failed("tryng to rotate a non initialized knt_struct!\n");
  }
  if ( knt_ptr->coord == NULL )
  {
    failed("tryng to rotate an empty knt_struct!\n");
  }
	//V1,V2 uniformly distributed between (-1,1), so that S=V1^2+V2^2<1
	do{
		V1=2*ran2(ptr_idum)-1;
		V2=2*ran2(ptr_idum)-1;
		s=V1*V1+V2*V2;
	}while(s>=1);
	dR=ran2(ptr_idum)*2.0;
	axis[0]=dR* 2*V1*sqrt(1-s);
	axis[1]=dR* 2*V2*sqrt(1-s);
	axis[2]=dR* (1-2*s);
	theta=ran2(ptr_idum)*PI;
	KNTLrotate(knt_ptr,axis,theta);
}



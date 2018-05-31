#include "KNT_simplify.h"
#include "my_memory.h"
#include "messages.h"
#include "prng.h"
#include "my_geom.h"
#include <math.h>
#include <string.h>

//double ** SIMP_BUFFER  = NULL;

#define DEBUG 0

int    check_viable_displacement_prd ( double  ** coord, int nsteps, int bead_moved, double *moved_bead_coordinate)
{

  //rispetto alla versione classica, i punti iniziale e finale della catena
  //non sono esclusi e viene utilizzato il modulo (%) di modo che coord[(N+1)%N]=coord[0]

  double pa[3],pb[3],pc[3],p1[3],p2[3],p[3];
  int j, k,ok;

  /* we don't want to consider the possibility to move the first and last points (coinciding) */

  //if ((bead_moved==0) || (bead_moved==(nsteps-1))) return(0);


  /* first triangle */
  for(k=0; k <3; k++){
    pa[k]=coord[(bead_moved-1+nsteps)%nsteps][k];
    pb[k]=coord[bead_moved][k];
    pc[k]=moved_bead_coordinate[k];
  }



  /* set of segments */
  for(j=0; j< (nsteps);  j++)
  {
    p1[0]=coord[j][0];
    p1[1]=coord[j][1];
    p1[2]=coord[j][2];
    p2[0]=coord[(j+1)%nsteps][0];
    p2[1]=coord[(j+1)%nsteps][1];
    p2[2]=coord[(j+1)%nsteps][2];
/*      for(k=0; k <3; k++){
        p1[k]=coord[j][k];
        p2[k]=coord[(j+1)%nsteps][k];
      }*/

      /* exclude from the checks of crossings the bonds involving the nodes "bead-moved-1" and "bead-moved" */
    if (j==((bead_moved-1+nsteps)%nsteps)) continue;
    if (((j+1)%nsteps)==((bead_moved-1+nsteps)%nsteps)) continue;
    if (j==(bead_moved)) continue;
    if (((j+1)%nsteps)==(bead_moved)) continue;

    if(LineFacet(p1,p2,pa,pb,pc,p)==TRUE){ok=0; return(ok);}

    }

  /* second triangle */

  for(k=0; k <3; k++){
    pa[k]=coord[bead_moved][k];
    pb[k]=moved_bead_coordinate[k];
    pc[k]=coord[(bead_moved+1)%nsteps][k];
  }


  /* set of segments */
  for(j=0; j< (nsteps);  j++)
  {
    p1[0]=coord[j][0];
    p1[1]=coord[j][1];
    p1[2]=coord[j][2];
    p2[0]=coord[(j+1)%nsteps][0];
    p2[1]=coord[(j+1)%nsteps][1];
    p2[2]=coord[(j+1)%nsteps][2];
    /*  for(k=0; k <3; k++){
        p1[k]=coord[j][k];
        p2[k]=coord[(j+1)%nsteps][k];
      }
      */

      /* exclude from the checks of crossings the bonds involving the nodes "bead-moved+1" and "bead-moved" */
      if (j==((bead_moved+1)%nsteps)) continue;
      if (((j+1)%nsteps)==(bead_moved+1)) continue;
      if (j==(bead_moved)) continue;
      if (((j+1)%nsteps)==(bead_moved)) continue;

      if(LineFacet(p1,p2,pa,pb,pc,p)==TRUE){ok=0; return(ok);}

    }
  ok=1;
  return(ok);
}

int    check_viable_displacement_sample ( double  ** coord, int * sample, int n_sample, int idx_bead_moved, double *moved_bead_coordinate)
{

  //rispetto alla versione classica, i punti iniziale e finale della catena
  //non sono esclusi e viene utilizzato il modulo (%) di modo che coord[(N+1)%N]=coord[0]

  double pa[3],pb[3],pc[3],p1[3],p2[3],p[3];
  int i,j,j_n, k,ok;
  int bead_moved, p_bead_moved, n_bead_moved;

  p_bead_moved = sample[(idx_bead_moved - 1 + n_sample)%n_sample];
  bead_moved   = sample[idx_bead_moved];
  n_bead_moved = sample[(idx_bead_moved + 1 )%n_sample];

  /* we don't want to consider the possibility to move the first and last points (coinciding) */

  //if ((bead_moved==0) || (bead_moved==(nsteps-1))) return(0);


  /* first triangle */
  for(k=0; k <3; k++){
    pa[k]=coord[p_bead_moved][k];
    pb[k]=coord[bead_moved][k];
    pc[k]=moved_bead_coordinate[k];
  }

  /* set of segments */
  for(i = 0; i< n_sample;  i++)
  {
    j = sample[i];
    j_n = sample[(i+1)%n_sample];
    p1[0]=coord[j][0];
    p1[1]=coord[j][1];
    p1[2]=coord[j][2];
    p2[0]=coord[j_n][0];
    p2[1]=coord[j_n][1];
    p2[2]=coord[j_n][2];
/*      for(k=0; k <3; k++){
        p1[k]=coord[j][k];
        p2[k]=coord[(j+1)%nsteps][k];
      }*/

      /* exclude from the checks of crossings the bonds involving the nodes "bead-moved-1" and "bead-moved" */
    if (i == ((idx_bead_moved-1+n_sample)%n_sample)) continue;
    if (((i+1)%n_sample)==((idx_bead_moved-1+n_sample)%n_sample)) continue;
    if (i == (idx_bead_moved)) continue;
    if ((( i +1)%n_sample)==(idx_bead_moved)) continue;

    if(LineFacet(p1,p2,pa,pb,pc,p)==TRUE){ok=0; return(ok);}

    }

  /* second triangle */

  for(k=0; k <3; k++){
    pa[k]=coord[bead_moved][k];
    pb[k]=moved_bead_coordinate[k];
    pc[k]=coord[n_bead_moved][k];
  }


  /* set of segments */
  for(i=0; i< n_sample;  i++)
  {
    j = sample[i];
    j_n = sample[(i+1)%n_sample];
    p1[0]=coord[j][0];
    p1[1]=coord[j][1];
    p1[2]=coord[j][2];
    p2[0]=coord[j_n][0];
    p2[1]=coord[j_n][1];
    p2[2]=coord[j_n][2];
    /*  for(k=0; k <3; k++){
        p1[k]=coord[j][k];
        p2[k]=coord[(j+1)%nsteps][k];
      }
      */

      /* exclude from the checks of crossings the bonds involving the nodes "bead-moved+1" and "bead-moved" */
      if (i==((idx_bead_moved+1)%n_sample)) continue;
      if (((i+1)%n_sample)==(idx_bead_moved+1)%n_sample) continue;
      if (i==(idx_bead_moved)) continue;
      if (((i+1)%n_sample)==(idx_bead_moved)) continue;

      if(LineFacet(p1,p2,pa,pb,pc,p)==TRUE){ok=0; return(ok);}

    }
  ok=1;
  return(ok);
}
/*
 * KNTLrectify_coord
 *
 * Simplify rings knt_ptr and save the simplified
 * coordinates and relative indexes in a new ring.
 *
 */

KNTarc * KNTLrectify_coord ( KNTarc * knt_ptr, int max_stride )
{
  int       i;
  KNTarc *  knt_rect = NULL;
  double ** dbuffer;
  int     * ibuffer;
  int       len;

  dbuffer  = d2t ( knt_ptr->len, 3 );
  ibuffer  = i1t ( knt_ptr->len    );

  if( knt_ptr->index == NULL )
  {
    for ( i = 0 ; i < knt_ptr->len ; i++ )
    {
      ibuffer[i] = i;
    }
  }
  else
  {
    for ( i = 0 ; i < knt_ptr->len ; i++ )
    {
      ibuffer[i] = knt_ptr->index[i];
    }
  }

  chain_remove_beads_new ( knt_ptr->len, knt_ptr->coord, &len, dbuffer, ibuffer ,max_stride);

  knt_rect = KNTinit_ptr ( );
  KNTadd_coord     ( len, dbuffer, ibuffer, knt_rect );
  KNTarc_SET_value ( knt_rect, start, 0, char );
  KNTarc_SET_value ( knt_rect, end, len, char );
  KNTarc_SET_value ( knt_rect, arc_type, knt_ptr->arc_type, char );
  strncpy ( knt_rect->closure, knt_ptr->closure, strlen(knt_ptr->closure) );
  strncpy ( knt_rect->simplification, SIMPRECT, strlen(SIMPRECT) );

  free_i1t ( ibuffer );
  free_d2t ( dbuffer );

  return knt_rect;
}

KNTarc * KNTLrectify_coord_local ( KNTarc * knt_ptr, int st_p, int end_p, int min_stride, int max_stride )
{
  int       i;
  KNTarc *  knt_rect = NULL;
  double ** dbuffer;
  int     * ibuffer;
  int       len;

  dbuffer  = d2t ( knt_ptr->len, 3 );
  ibuffer  = i1t ( knt_ptr->len    );

  if( knt_ptr->index == NULL )
  {
    for ( i = 0 ; i < knt_ptr->len ; i++ )
    {
      ibuffer[i] = i;
    }
  }
  else
  {
    for ( i = 0 ; i < knt_ptr->len ; i++ )
    {
      ibuffer[i] = knt_ptr->index[i];
    }
  }

  if (max_stride != 0)
  {
    chain_remove_beads_local ( knt_ptr->len, knt_ptr->coord, st_p, end_p, &len, dbuffer, ibuffer ,min_stride,max_stride);
  }
  else
  {
    for(i=0;i<knt_ptr->len;i++)
    {
      dbuffer[i][0]=knt_ptr->coord[i][0];
      dbuffer[i][1]=knt_ptr->coord[i][1];
      dbuffer[i][2]=knt_ptr->coord[i][2];
    }
    len = knt_ptr->len;
  }
  knt_rect = KNTinit_ptr ( );
  KNTadd_coord     ( len, dbuffer, ibuffer, knt_rect );
  KNTarc_SET_value ( knt_rect, start, 0, char );
  KNTarc_SET_value ( knt_rect, end, len, char );
  KNTarc_SET_value ( knt_rect, arc_type, knt_ptr->arc_type, char );
  strncpy ( knt_rect->closure, knt_ptr->closure, strlen(knt_ptr->closure) );
  strncpy ( knt_rect->simplification, SIMPRECT, strlen(SIMPRECT) );

  free_i1t ( ibuffer );
  free_d2t ( dbuffer );

  return knt_rect;
}

/*
 * chain_remove_beads_new
 *
 * Rectify the chain oldcoord[oldlen][3]
 * and store the result in coord[newlen][3].
 * index is an array with the indexes of every bead.
 * if index == NULL the array is generated locally.
 *
 * Using the index array the function is able to
 * smoothly erase beads with incremental stride and
 * to keep track of which are the remaining beads.
 *
 * Rectification procedure: randomly choose a point j.
 * if abs(index[j-1] - index[j+1) < stride) substitute
 * the point j with 0.5*(j-1) + 0.5(j+1). If the substitution
 * does not alter the topology of the whole ring
 * (LineFacet evaluates this condition), accept the substitution
 * and erase point j. Otherwise choose another point.
 * Repeat the procedure len times. set stride = 2*stride
 * and repeat.
 *
 * The procedure continues until no points can be erased at a given
 * stride.
 */


void chain_remove_beads_new ( int oldlen, double ** oldcoord, int *newlen, double ** coord, int * index, int max_stride)
{
  int     i, j, k, iter;
  int     i_start, i_end, lin_dist;
  int     len,templen;
  int     ok, ok1, ok2;
  int     gap, stride;
  int     index_local_init = FALSE;
  int      * tempindex;
  double  ** tempcoord;
  //extern long int     * ptr_idum;
#if FOLLOW_BY
  FILE    *fp;
  char    nameout[512];
  int     flwby_stride = 1;
#endif

  /*
   * allocate memory for indexes arrays,
   * if index array is NULL, initialize it.
   */
  len = oldlen;
  tempindex = i1t ( len );

  if( max_stride < 0 || max_stride  > len)
  {
    max_stride = 4*len;
  }
  /*
   * set tempindex to index and stride to the
   * minimum gap in the old chain.
   *
   * In fact I am not setting to the minimum gap,
   * because I can't go around the chain without knowing
   * its original length. That's why the loop stops for i < len - 1
   */
  if ( index != NULL )
  {
    stride = len;
    for( i = 0 ; i < len - 1 ; i++ )
    {
      tempindex [i] = index[i];
      if((gap = abs(index[(i+1)%len]-index[i])) < stride)
      {
        stride = 2*gap;
      }
    }
  }
  else
  {
    index = i1t ( len );
    index_local_init = TRUE;
    stride = 2;
    for ( i = 0 ; i < len ; i++ )
    {
      tempindex[i] = index[i] = i;
    }
  }

  if ( stride < 2 )
  {
    stride = 2;
  }
  /*
   * do the same with the coordinates
   */
  //if ( SIMP_BUFFER == NULL )
  //{
    tempcoord = d2t ( oldlen, 3 );
  //}
  //else
  //{
  //  tempcoord = SIMP_BUFFER;
  //}
  copy_chain      ( oldcoord, oldlen, coord );
  //len = oldlen;

#if DEBUG == 3
  if(max_stride < oldlen)
    fprintf(stderr, "initial stride %d\n",stride );
#endif
  //stride = 2;
  do
  {
    *newlen = len;
    for( iter = 0 ; iter < *newlen ; iter++ )
    {
      /* pick bead to remove */
      j = ranint_(len); 
      i_start = ( j - 1 + len ) % len;
      i_end   = ( j + 1       ) % len;
      copy_chain ( coord, len, tempcoord );
      templen = len;
      //proponi rettificazione
      for( k = 0 ; k < 3 ; k++ )
      {
        tempcoord[j][k] = 0.5 * ( coord[i_start][k] + coord[ i_end ][k]);
      }

      ok = 0;
      lin_dist = ( index[i_end] > index[i_start] ) ? index[i_end] - index[i_start] : index[i_end] - index[i_start] + oldlen;
      //la riga seguente controlla il grado di semplificazione.
      if( abs ( lin_dist ) <= stride)
      {
        ok1 = 1;
#if DEBUG == 3
        if ( max_stride < oldlen )
        fprintf(stderr,"-----------------\nindex j:%10d\nj-1\t%10d\nj+1\t%10d\ndistance%10d\nlen\t%10d\n",
            index[j],index[i_start],index[i_end], abs ( lin_dist ),len);
#endif
      }
      else
      {
        ok1 = 0;
      }
      //valuta tramite LineFacet
      //Se la mossa viene accettata,ricopia la catena temp in quella da semplificare
      //saltando il punto j.La lunghezza della catena va aggiornata di conseguenza.
      if ( ok1 )
        ok2 = check_viable_displacement_prd ( coord, len, j, tempcoord[j] );
      else
        ok2 = 0;
      if ( ok2 )
      {
        templen = 0;
        for( i = 0 ; i < len ; i++ )
        {
          if ( i == j ) continue;
          for( k = 0 ; k < 3 ; k++ )
          {
            tempcoord[templen][k] = coord[i][k];
          }
          tempindex [templen] = index[i];
          templen++;
        }
        ok = 1;
      }

      /* accept */
      if ( ok == 1 )
      {
        copy_chain ( tempcoord, templen, coord );
        len = templen;
        for ( i = 0 ; i < templen ; i++)
        {
          index [i] = tempindex [i];
        }
        if( len < 4 )
        {
          *newlen = len;
          //if ( SIMP_BUFFER == NULL )
          //{
            free_d2t( tempcoord );
          //}
          free_i1t( tempindex );
          if ( index_local_init )
          {
            free_i1t ( index );
          }
          return ;
        }
      }
      /* Reject */
      else
      {
        copy_chain ( coord, len, tempcoord);
        templen = len;
        for ( i = 0 ; i < templen ; i++ )
        {
          tempindex [i] = index[i];
        }
      }

#if FOLLOW_BY
      if ( flwby_stride <= 0 )
        continue;
      if ( ( iter % ( flwby_stride * oldlen )) == 0)
      {
        printf                ( "remove. iteration %5d. length %3d. \n", iter, len);
        printf                ( "Appending configuration to pdbfile \n"           );
        new_dump_coord_to_pdb ( tempcoord, len );
        sprintf               ( nameout, "%s_temp_inflated.xyz", in_file_name     );
        fp      =       fopen ( nameout, "w"   );
        write_configuration   ( fp, coord,  len);
        fclose(fp);
      }
#endif
    }

#if DEBUG == 3
    if ( max_stride < oldlen )
      fprintf(stderr,"used stride = %d -- max_stride = %d\n",stride,max_stride);
#endif
    if( stride * 2 > max_stride && stride < max_stride )
    {
      stride = max_stride;
    }
    else
    {
      stride = stride * 2;
    }
    if(stride > max_stride)
    {
      *newlen = len;
    }
  }while( len != *newlen );
#if DEBUG == 3
  if(max_stride < oldlen)
    fprintf(stderr,"stride = %d\n",stride);

  if(max_stride < oldlen)
  {
    fprintf(stderr,"%d\n",*newlen+1);
    for ( i = 0; i < len ; i++)
      fprintf(stderr,"%4d %9.4lf %9.4lf %9.4lf\n",index[i], coord[i][0], coord[i][1],coord[i][2]);
    fprintf(stderr,"%4d %9.4lf %9.4lf %9.4lf\n",index[0], coord[0][0], coord[0][1],coord[0][2]);
  }
#endif


  //if ( SIMP_BUFFER == NULL )
  //{
    free_d2t( tempcoord );
  //}
  free_i1t( tempindex );
  if ( index_local_init )
  {
    free_i1t ( index );
  }
}

void chain_remove_beads_w_shuffle_nostride ( int oldlen, double ** oldcoord, int *newlen, double ** coord)
{
  int     i, j, k;
  int     temp, range;
  int     i_start, i_remove, i_end;
  int     len;
  int      * tempindex;
  int       * index;
  double   moved_bead[3];
  //extern long int     * ptr_idum;

  /*
   * allocate memory for indexes arrays,
   * if index array is NULL, initialize it.
   */
  tempindex = i1t ( oldlen );
  index     = i1t ( oldlen );
  *newlen = len = oldlen;

  /*
   * set tempindex to index and stride to the
   * minimum gap in the old chain.
   *
   * In fact I am not setting to the minimum gap,
   * because I can't go around the chain without knowing
   * its original length. That's why the loop stops for i < len - 1
   */
  for ( i =0 ; i < oldlen ;i++ )
  {
    tempindex[i] = i;
    index[i]  = i;
  }

  /*
   * do the same with the coordinates
   */
  do
  {
    *newlen = len;
    if ( len < 5 ) { break; } //no need to further simplify the chain..
    //FY SHUFFLE of index till len
    for ( j = len-1 ; j > 0 ; j--)
    {
      //from the last idx to the next-to-first
      //ie for indices 0..N-1 we go from N-1 to 1
      range = j+1;
      //cerr << "Range is:\t" << range << endl;
			k = ranint_(range);
      temp = tempindex[k];
      tempindex[k] = tempindex[j];
      tempindex[j] = temp;
    }
    i = 0;
    do
    {
      /*fprintf(stderr,"%d\n",oldlen);
      for ( k = 0; k < len; k++ )
      {
        fprintf(stderr,"%lf %lf %lf\n",oldcoord[index[k]][0],oldcoord[index[k]][1],oldcoord[index[k]][2]);
      }
      for ( k = len; k < oldlen; k++ )
      {
        fprintf(stderr,"%lf %lf %lf\n",oldcoord[0][0],oldcoord[0][1],oldcoord[0][2]);
      }*/
      //Now I can walk through the shuffled array.
      i_start = ( tempindex[i]-1+len )%len;
      i_end   = ( tempindex[i]+1 )%len;
      i_start = index[i_start];
      i_end   = index[i_end];
      i_remove = tempindex[i];
      for( k = 0 ; k < 3 ; k++ )
      {
        moved_bead[k] = 0.5 * ( oldcoord[i_start][k] + oldcoord[ i_end ][k]);
      }
      if ( check_viable_displacement_sample ( oldcoord, index, len, i_remove, moved_bead))
      {
        //update reference vector tempindex
        for ( j = 0; j < len ; j++ )
        {
          if ( tempindex[j] > i_remove )
          {
            tempindex[j]--;
          }
        }
        //erase i_remove from index
        for ( j = i_remove + 1; j < len ; j++)
        {
          index[j-1] = index[j];
        }
        //move last tempindex to current position, to analyze at next step.
        tempindex[i] = tempindex[ len - 1 ];
        //reduce dimension of the sample to be analyzed (i.e. erasing moved_bead from the sample!)
        len--;
      }
      else
      {
        i++;
      }

    //}while ( i != len && len>=5);
    }while ( i < len && len>=5);
    //now increase the stride
  }while ( len != *newlen);
  //copy the coordinates!
  for ( i = 0 ; i < len ; i++ )
  {
    j = index[i];
    coord[i][0] = oldcoord[j][0];
    coord[i][1] = oldcoord[j][1];
    coord[i][2] = oldcoord[j][2];
  }
  free_i1t( tempindex );
  free_i1t( index );
}

int chain_remove_beads_local ( int oldlen, double ** oldcoord,int start,int end, int *newlen, double ** coord, int * index,int min_stride, int max_stride)
{
  int     i, j, k, iter;
  int     len,templen;
  int     lin_dist;
  int     i_start,i_end;
  int     seg_len;
  int     ok, ok1;
  int     gap, stride;
  int     index_local_init = FALSE;
  int      * tempindex;
  double  ** tempcoord;
  //extern long int     * ptr_idum;
#if FOLLOW_BY
  FILE    *fp;
  char    nameout[512];
  int     flwby_stride = 1;
#endif

  /*
   * alloc memory for indexes arrays,
   * if index array is NULL, initialize it.
   */
  len = oldlen;
  tempindex = i1t ( len );
	// XXX add a guard for out of bound start or end.
  seg_len = start > end ?  len - start + end : end - start;
  if( max_stride < 0 || max_stride  > seg_len)
  {
    max_stride = 4*seg_len;
  }

  /*
   * set tempindex to index and stride to the
   * minimum gap in the old chain.
   *
   * In fact I am not setting to the minimum gap,
   * because I can't go around the chain without knowing
   * its original length. That's why the loop stops for i < len - 1
   */
  if ( index != NULL )
  {
    stride = len;
    for( i = 0 ; i < len - 1 ; i++ )
    {
      tempindex [i] = index[i];
      if((gap = abs(index[(i+1)%len]-index[i])) < stride)
      {
        stride = 2*gap;
      }
    }
    tempindex [len-1] = index[len-1]; //QUESTO MANCAVA!
  }
  else
  {
    index = i1t ( len );
    index_local_init = TRUE;
    stride = 2;
    for ( i = 0 ; i < len ; i++ )
    {
      tempindex[i] = index[i] = i;
    }
  }

  if ( stride < 2 )
  {
    stride = 2;
  }

  if ( min_stride != DONT_CARE)
  {
    stride = min_stride;
  }

  /*
   * do the same with the coordinates
   */
  tempcoord = d2t ( oldlen, 3 );
  copy_chain      ( oldcoord, oldlen, coord );
  //len = oldlen;

#if DEBUG == 3
  fprintf(stderr, "initial stride %d\n",stride );
#endif
  //stride = 2;
  do
  {
    *newlen=len;
    for( iter = 0 ; iter < *newlen ; iter++ )
    {
      /* pick bead to remove */
      //j = ((int) floor ( ran2( ptr_idum ) * seg_len ) + start) % len;
      j = (ranint_(seg_len) + start) % len;
      i_start = ( j - 1 + len ) % len;
      i_end   = ( j + 1       ) % len;
      copy_chain ( coord, len, tempcoord );
      templen = len;
      //proponi rettificazione
      for( k = 0 ; k < 3 ; k++ )
      {
        tempcoord[j][k] = 0.5 * ( coord[( j - 1 + len ) % len][k] + coord[ ( j + 1 ) % len][k]);
      }

      ok = 0;
      lin_dist = ( index[i_end] > index[i_start] ) ? index[i_end] - index[i_start] : index[i_end] - index[i_start] + oldlen;
      //la riga seguente controlla il grado di semplificazione.
      if( abs ( lin_dist ) <= stride)
        ok1 = 1;
      else
        ok1 = 0;
      //valuta tramite LineFacet
      //Se la mossa viene accettata,ricopia la catena temp in quella da semplificare
      //saltando il punto j.La lunghezza della catena va aggiornata di conseguenza.
      if ( ok1 && (check_viable_displacement_prd ( coord, len, j, tempcoord[j] ) == 1 ) && j != start && index[j] != end)
      {
        templen = 0;
        for( i = 0 ; i < len ; i++ )
        {
          if ( i == j ) continue;
          for( k = 0 ; k < 3 ; k++ )
          {
            tempcoord[templen][k] = coord[i][k];
          }
          tempindex [templen] = index[i];
          templen++;
        }
        ok = 1;
        seg_len--;
        if ( j < start )
          start = ( start - 1 + len )%len;
      }

      /* accept */
      if ( ok == 1 )
      {
        copy_chain ( tempcoord, templen, coord );
        len = templen;
        for ( i = 0 ; i < templen ; i++)
        {
          index [i] = tempindex [i];
        }
        if( len < 4 )
        {
          *newlen = len;
          free_d2t( tempcoord );
          free_i1t( tempindex );
          if ( index_local_init )
          {
            free_i1t ( index );
          }
          return seg_len;
        }
      }
      /* Reject */
      else
      {
        copy_chain ( coord, len, tempcoord);
        templen = len;
        for ( i = 0 ; i < templen ; i++ )
        {
          tempindex [i] = index[i];
        }
      }

#if FOLLOW_BY
      if ( flwby_stride <= 0 )
        continue;
      if ( ( iter % ( flwby_stride * oldlen )) == 0)
      {
        printf                ( "remove. iteration %5d. length %3d. \n", iter, len);
        printf                ( "Appending configuration to pdbfile \n"           );
        new_dump_coord_to_pdb ( tempcoord, len );
        sprintf               ( nameout, "%s_temp_inflated.xyz", in_file_name     );
        fp      =       fopen ( nameout, "w"   );
        write_configuration   ( fp, coord,  len);
        fclose(fp);
      }
#endif
    }
    //fprintf(stderr, "\n"); //RAN2 DEBUG
#if DEBUG == 3
    if ( max_stride < oldlen )
      fprintf(stderr,"used stride = %d -- max_stride = %d\n",stride,max_stride);
#endif
    if( stride * 2 > max_stride && stride < max_stride )
    {
      stride = max_stride;
    }
    else
    {
      stride = stride * 2;
    }
    if(stride > max_stride)
    {
      *newlen = len;
    }

  }while( len != *newlen );

  free_d2t( tempcoord );
  free_i1t( tempindex );
  if ( index_local_init )
  {
    free_i1t ( index );
  }
  return seg_len;
}



void copy_chain(double ** coord,int len, double ** coordnew)
{
  int i;
  for ( i = 0 ; i < len ; i++ )
  {
    coordnew[i][0] = coord[i][0];
    coordnew[i][1] = coord[i][1];
    coordnew[i][2] = coord[i][2];
  }
}


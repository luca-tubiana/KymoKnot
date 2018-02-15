#include "KNT_arc.h"
#include "KNT_table.h"
#include "my_memory.h"
#include "messages.h"
#include <stdlib.h>
#include <string.h>



const KNTarc KNTarc_DEFAULT = { DONT_CARE,                            // arc_type
                          DONT_CARE, DONT_CARE,                       // start and end
                          DONT_CARE,                                  // len
                          NULL, NULL,NULL,                            // coord, index, kntmatrix
                          STR_DONT_CARE,STR_DONT_CARE,STR_DONT_CARE,  // closure, type, simplification
                          //TOPOLOGICAL PROPERTIES
                          //DONT_CARE, DONT_CARE,                     // Adet_1, Adet_2
													_KNTid_DEFAULT,                              //knot identifier
                          (double) DONT_CARE, (double) DONT_CARE,     // cross, scross
                          (double) DONT_CARE,                         // writhe
                          //GEOMETRICAL PROPERTIES
                          (double) DONT_CARE, (double) DONT_CARE,     // ch_area, ch_vol
                          (double) DONT_CARE, (double) DONT_CARE, (double) DONT_CARE, // A, P, Rg
                          (double) DONT_CARE,                         // Rc
                          {(double) DONT_CARE,(double) DONT_CARE, (double) DONT_CARE}, // cm[3]
                          //FLAGS
                          FALSE,TRUE,                                 //is_alloc, is_init
                          FALSE,                                      // flag_arc_type
                          FALSE,FALSE,FALSE,                          // flag_len, flag_start,flag_end
                          //FALSE,FALSE,                              // flag_Adet_1, flag_Adet_2
													FALSE,                                       // flag_knot_type
                          FALSE,FALSE,                                // flag_cross, flag_scross
                          FALSE,                                      // flag_writhe
                          FALSE,FALSE,                                // flag_ch_area, flag_ch_vol
                          FALSE,FALSE,FALSE,                          // flag_A, flag_P, flag_Rg
                          FALSE,                                      // flag_Rc
                          FALSE,                                      // flag_cm
                          //POINTER TO NEXT ELEMENT IN LIST
                          NULL};


void KNTreset ( KNTarc * knt_ptr )
{
  * knt_ptr = KNTarc_DEFAULT;
}

/*
 * KNTpush
 *
 * Add a member to the knt_ptr list
 * or initializes it if empty.
 *
 * Returns a pointer to the  added element.
 *
 */
KNTarc * KNTpush (KNTarc *knt_ptr, KNTarc *el )
{
  KNTarc * last;
  last = KNTlast ( knt_ptr );
  if ( last == NULL )
  {
    failed ("KNTpush: using wrongly initialized KNTarc \n");
  }
  last->next = KNTcopy_el(el);
  last = last->next;
  return last;
}


/*
 * KNTlast
 *
 * Returns last non-empty element
 * stored in the list knt_ptr, or
 * NULL if the list is empty.
 */
KNTarc * KNTlast ( KNTarc * knt_ptr )
{
  KNTarc * last = knt_ptr;
  if ( last != NULL )
  {
    if(last->is_init == FALSE)
    {
      KNTfree_arc(last);
      return NULL;
    }
    while ( last->next != NULL )
    {
      last = last->next;
    }
  }

  return last;
}


KNTarc KNTinit( )
{
  KNTarc knt = KNTarc_DEFAULT;
  return knt;
}

KNTarc * KNTinit_ptr( )
{
  KNTarc * knt_ptr;

  knt_ptr = malloc ( sizeof( KNTarc ) );

  if(knt_ptr == NULL)
  {
    failed("failed to allocate memory for knot structure\n");
  }

  KNTreset(knt_ptr);
  knt_ptr->is_alloc = TRUE;

  return knt_ptr;
}

void KNTadd_matrix( KNTarc * knt_ptr )
{
  int      i, j;

  if( !(KNTarc_isSET(knt_ptr,len)) )
  {
    failed("KNTadd_matrix: knt_ptr->len not set\n");
  }
  if(knt_ptr->kntmatrix == NULL )
  {
    knt_ptr->kntmatrix = s2t(knt_ptr->len,knt_ptr->len);

    for ( i = 0 ; i < knt_ptr->len ; i++ )
    {
      for ( j = 0 ; j < knt_ptr->len ; j++ )
      {
        knt_ptr->kntmatrix[i][j] = ( short ) DONT_CARE;
      }
    }
  }
  else
  {
    failed("KNTadd_matrix: tryng to append matrix to non - NULL pointer\n");
  }
}

/*
 * KNTadd_coord
 *
 * IN:
 *  len     : length of coord and index arrays.
 *  coord   : coordinate matrix of dims len x 3 or NULL
 *  index   : index array or NULL
 *  knt_ptr : KNTarc pointer to store results. knt_ptr->coord and
 *            knt_ptr->index must be NULL.
 *
 * OUT:
 *  knt_ptr.
 *
 */
void KNTadd_coord ( int len, double ** coord, int * index, KNTarc * knt_ptr )
{
  int      i, j;

  if( (KNTarc_isSET(knt_ptr,len)) )
  {
    failed("KNTadd_coord: trying to overwrite already set knt_ptr->len\n");
  }
  if(knt_ptr->coord == NULL && knt_ptr->index == NULL )
  {
    KNTarc_SET_value(knt_ptr,len,len,int);
    knt_ptr->coord = d2t ( knt_ptr->len, 3 );
    knt_ptr->index = i1t ( knt_ptr->len    );

    if ( coord == NULL && index != NULL)
    {
      fprintf ( stderr, "KNTadd_coord: coord == NULL but index == %p\n",index);
      exit(1);
    }
    else if(coord == NULL && index == NULL)
    {
      for ( i = 0 ; i < knt_ptr->len ; i++ )
      {
        for ( j = 0 ; j < 3 ; j++ )
        {
          knt_ptr->coord[i][j] = ( double ) DONT_CARE;
        }
        knt_ptr->index[i] = i;
      }
    }
    else if ( index == NULL )
    {
      for ( i = 0 ; i < knt_ptr->len; i++)
      {
        for ( j = 0 ; j < 3 ; j++ )
        {
          knt_ptr->coord[i][j] = coord[i][j];
        }
        knt_ptr->index[i] = i;
      }
    }
    else
    {
      for ( i = 0 ; i < knt_ptr->len ; i++ )
      {
        for ( j = 0 ; j < 3 ; j++ )
        {
          knt_ptr->coord[i][j] = coord[i][j];
        }
        knt_ptr->index[i] = index[i];
      }
    }
  }
  else
  {
    failed("KNTadd_coord: tryng to append coord or index to non - NULL pointer\n");
  }
}

/*
 * KNTinit_matrix_ptr
 *
 * IN: length of coordinates array
 *
 * OUT: a pointer to an initialized knot_arc
 *      structure with a kntmatrix of dims len x len.
 *
 * If allocation fails, the whole program exits!
 */
KNTarc * KNTinit_matrix_ptr( int len )
{
  int      i, j;
  KNTarc * knt_ptr;

  knt_ptr = malloc ( sizeof( KNTarc ) );

  if(knt_ptr == NULL)
  {
    failed("failed to allocate memory for knot structure\n");
  }

  KNTreset(knt_ptr);
  knt_ptr->len       = len;
  knt_ptr->is_alloc  = TRUE;
  knt_ptr->kntmatrix = s2t(knt_ptr->len,knt_ptr->len);

  for ( i = 0 ; i < knt_ptr->len ; i++ )
  {
    for ( j = 0 ; j < knt_ptr->len ; j++ )
    {
      knt_ptr->kntmatrix[i][j] = ( short ) DONT_CARE;
    }
  }

  return knt_ptr;
}

/*
 * KNTinit_matrix_ptr
 *
 * IN: length of coordinates array
 *
 * OUT: an initialized knot_arc
 *      structure with a kntmatrix of dims len x len.
 *
 */

KNTarc  KNTinit_matrix( int len )
{
  int      i, j;
  KNTarc  knt;
  KNTarc *knt_ptr;

  knt_ptr = &knt;
  KNTreset(knt_ptr);
  knt.is_alloc  = FALSE;
  knt.len       = len;
  knt.kntmatrix = s2t(knt_ptr->len,knt_ptr->len);

  for ( i = 0 ; i < knt_ptr->len ; i++ )
  {
    for ( j = 0 ; j < knt_ptr->len ; j++ )
    {
      knt_ptr->kntmatrix[i][j] = ( short ) DONT_CARE;
    }
  }

  return knt;
}


void KNTfree_arc(KNTarc * knt_ptr)
{

  if(knt_ptr->next      != NULL)
  {
    KNTfree_arc(knt_ptr->next);
    knt_ptr->next = NULL;
  }
  if(knt_ptr->coord     != NULL)
    free_d2t(knt_ptr->coord);

  if(knt_ptr->index     != NULL)
    free_i1t(knt_ptr->index);

  if(knt_ptr->kntmatrix != NULL)
    free_s2t(knt_ptr->kntmatrix);

  if(KNTarc_isALLOC(knt_ptr))
  {
    free(knt_ptr);
    knt_ptr = NULL;
  }
}

KNTarc* KNTremove_arc(KNTarc *knt_ptr)
{
	if(knt_ptr == NULL)
	{
		failed("KNTremove_arc: trying to access non-allocated list");
	}
	KNTarc *knt_next=knt_ptr->next;
  if(knt_ptr->coord     != NULL)
    free_d2t(knt_ptr->coord);

  if(knt_ptr->index     != NULL)
    free_i1t(knt_ptr->index);

  if(knt_ptr->kntmatrix != NULL)
    free_s2t(knt_ptr->kntmatrix);

  if(KNTarc_isALLOC(knt_ptr))
  {
    free(knt_ptr);
    knt_ptr = NULL;
  }
	return knt_next;
}


KNTarc * KNTcopy_el ( KNTarc * knt_ptr)
{
  int i, j;
  KNTarc * knt_new;

  if ( knt_ptr == NULL )
    return NULL;

  /* if we are trying to copy an unitialized or unallocated structure, fail!*/
  /*if ( knt_ptr->is_alloc == FALSE )
  {
    failed("tryng to copy a non allocated knt_struct!\n");
  }
  */
  else if ( knt_ptr->is_init == FALSE )
  {
    failed("tryng to copy a non initialized knt_struct!\n");
  }

  knt_new = KNTinit_ptr();


  /*copy arrays*/
  if ( KNTarc_isSET(knt_ptr,cm))
  {
    for ( i = 0 ; i < 3 ; i++ )
    {
      knt_new->cm[i] = knt_ptr->cm[i];
    }
    knt_new->flag_cm = TRUE;
  }
  if ( knt_ptr->coord != NULL )
  {
    if ( knt_ptr->index == NULL )
    {
      fprintf(stderr,"WARNING! in KNTcopy. knt_ptr contains a set of coordinate without corresponding indexes\n.");
      fprintf(stderr,"\t\t adding indexes in the copy\n.");
      KNTadd_coord(knt_ptr->len,knt_ptr->coord,NULL,knt_new);
    }
    else
    {
      KNTadd_coord(knt_ptr->len,knt_ptr->coord,knt_ptr->index,knt_new);
    }
  }
  if ( knt_ptr->kntmatrix != NULL )
  {
    KNTadd_matrix( knt_new );
    for ( i = 0; i < knt_new->len; i++ )
    {
      for ( j =0 ; j < knt_new->len; j++ )
      {
        knt_new->kntmatrix[i][j] = knt_ptr->kntmatrix[i][j];
      }
    }
  }

  KNTarc_SETif(knt_new,arc_type,knt_ptr->arc_type,knt_ptr->arc_type,char);
  KNTarc_SETif(knt_new,start,knt_ptr->start,knt_ptr->start,int);
  KNTarc_SETif(knt_new,end,knt_ptr->end,knt_ptr->start,int);
  KNTarc_SETif(knt_new,len,knt_ptr->len,knt_ptr->len,int);
  //KNTarc_SETif(knt_new,Adet_1,knt_ptr->Adet_1,int);
  //KNTarc_SETif(knt_new,Adet_2,knt_ptr->Adet_2,int);
	KNTarc_SETif(knt_new,knot_type,knt_ptr->knot_type,knt_ptr->knot_type.k_id,KNTid);

  KNTarc_SETif(knt_new,cross,knt_ptr->cross,knt_ptr->cross,double);
  KNTarc_SETif(knt_new,scross,knt_ptr->scross,knt_ptr->scross,double);
  KNTarc_SETif(knt_new,writhe,knt_ptr->writhe,knt_ptr->writhe,double);

  KNTarc_SETif(knt_new,ch_area,knt_ptr->ch_area,knt_ptr->ch_area,double);
  KNTarc_SETif(knt_new,ch_vol,knt_ptr->ch_vol,knt_ptr->ch_vol,double);
  KNTarc_SETif(knt_new,A,knt_ptr->A,knt_ptr->A,double);
  KNTarc_SETif(knt_new,P,knt_ptr->P,knt_ptr->P,double);
  KNTarc_SETif(knt_new,Rg,knt_ptr->Rg,knt_ptr->Rg,double);
  KNTarc_SETif(knt_new,Rc,knt_ptr->Rc,knt_ptr->Rc,double);
  /* copy strings */
  if ( knt_ptr->closure != NULL)
  {
  strncpy(knt_new->closure,knt_ptr->closure,strlen(knt_ptr->closure));
  }
  if ( knt_ptr->type!= NULL)
  {
  strncpy(knt_new->type,knt_ptr->type,strlen(knt_ptr->type));
  }
  if ( knt_ptr->simplification!= NULL)
  {
  strncpy(knt_new->simplification,knt_ptr->simplification,strlen(knt_ptr->simplification));
  }

  knt_new->is_init=TRUE;
  knt_new->is_alloc=TRUE;
  knt_new->next = NULL;

  return knt_new;
}






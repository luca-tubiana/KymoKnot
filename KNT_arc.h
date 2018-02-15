/*************************************************/
/*14-12-2010 Luca Tubiana                        */
/*This header provides definitions and prototypes*/
/*to implement the struct knot_arc and use it    */
/*in a program with hdf5 file i/o                */
/*************************************************/

#ifndef HDR_KNTARC
#define HDR_KNTARC

//#include "my_memory.h"
#include "KNT_defaults.h"
#include "KNT_table.h"

/***MACROS********************************************/
#define KNTarc_SET_value(ptr,name, val, type) \
  (ptr)->name = ( type ) ( val ); \
  (ptr)->flag_##name = TRUE;

#define KNTarc_isSET(ptr,name) \
  (ptr)->flag_##name

#define KNTarc_SETif(ptr, name, val,chk, type) \
  if( (int) chk != (int) DONT_CARE ) \
  { \
    (ptr)->name = ( type ) ( val ); \
    (ptr)->flag_##name = TRUE; \
  }


#define KNTarc_GETif(ptr,name, out,chk, type) \
  if( (ptr)->flag_##name ) \
  {                    \
		chk= TRUE; \
    out = ( type ) (ptr)->name; \
  } \
  else \
  { \
    chk = DONT_CARE; \
  }


#define KNTarc_isALLOC(ptr) \
  (ptr)->is_alloc

/*
 * The macro KNTarc_SET_value will not work if an argument like (double*) is passed.
 *Therefore one needs to typedef all pointers.
 */
typedef  double * double_ptr;
typedef  float  * float_ptr;
typedef  int    * int_ptr;
typedef  long   * long_ptr;
typedef  short  * short_ptr;
typedef  KNTid  * KNTid_ptr;

#define DONT_CARE_double 	DONT_CARE
#define DONT_CARE_float 	DONT_CARE
#define DONT_CARE_int   	DONT_CARE
#define DONT_CARE_long  	DONT_CARE
#define DONT_CARE_short 	DONT_CARE
#define DONT_CARE_KNTid 	_KNTid_DEFAULT

/**************************************************************/
/*The following structure contains the main                   */
/*variables used to define the geometric and                  */
/*topological properties of a knotted arc or                  */
/*ring. It is structured as a node of a linked                */
/*list in order to allow storage of the whole                 */
/*ring and any subarc of interest.                            */
/*This scheme will probably turn out to be                    */
/*useful for other purposes in the future                     */
/**************************************************************/

struct knot_arc {
  char        arc_type;        /*identifier for arc_type. RING, shortest_knotted, shortest_c_knotted, any arc*/
  int         start, end;      /*start and end of arc (0, len) if ring or linear                             */
  int         len;             /*arc's length. coord[len][3];                                                */
  double   ** coord;           /*arc's coordinates                                                           */
  int       * index;           /*arc  bead's indexes. Keep trace of the effects of a simplification.         */
  short    ** kntmatrix;       /*knot matrix. Use carefully...                                               */
  char        closure[STR_OUT_MAXLEN];         /*a string containing an explanation of the closure."ring" if it is a ring.   */
  char        type[STR_OUT_MAXLEN];            /*knot type (3_1, 4_1, 5_1, 3_1#3_1..etc)                                     */
  char        simplification[STR_OUT_MAXLEN];  /*simplification scheme adopted                                               */
  //int         Adet_1, Adet_2;  /*Alexander determinants in -1 and -2                                         */
	KNTid				knot_type;
  double      cross, scross;   /*average crossing number and average signed crossing number    (Unused)      */
  double      writhe;          /*writhe of the ring                       (Unused)                           */

  double      ch_area, ch_vol; /* Convex hull area and volume (Unused)                                       */
  double      A,P,Rg;          /*Asphericity, Prolateness, Gyration radius (Unused)                          */
  double      Rc;              /*Radius of confining sphere.       (Unused)                                  */
  double      cm[3];           /*center of mass.                                                             */
  /* flags. 0: value unassigned. >0 value set. use to save data.      */
  short       is_alloc,is_init;

  short       flag_arc_type;
  short       flag_len,flag_start, flag_end;
  //short       flag_Adet_1, flag_Adet_2;
	short 			flag_knot_type;
  short       flag_cross, flag_scross, flag_writhe;
  short       flag_ch_area, flag_ch_vol;
  short       flag_A, flag_P, flag_Rg, flag_Rc, flag_cm;

  struct knot_arc * next;   /*pointer to another arc*/
};


typedef struct knot_arc       KNTarc;


/* PROTOTYPES-----------------------------*/
/*--initialization and memory allocation--*/
void        KNTreset           ( KNTarc * );
KNTarc*     KNTremove_arc       ( KNTarc *);
KNTarc    * KNTpush            ( KNTarc * ,KNTarc *);
KNTarc    * KNTlast            ( KNTarc * );
KNTarc      KNTinit            (          );
KNTarc    * KNTinit_ptr        (          );
KNTarc      KNTinit_matrix     ( int      );
KNTarc    * KNTinit_matrix_ptr ( int      );
void        KNTadd_matrix      ( KNTarc * );
void        KNTadd_coord       ( int, double **, int *, KNTarc * );
/*--copy------------------------------------*/
//KNTarc    * KNTcopy            ( KNTarc * );
KNTarc    * KNTcopy_el            ( KNTarc * );
/*--free memory-----------------------------*/
void        KNTfree_arc        ( KNTarc * );




#endif /*HDR_KNTARC */

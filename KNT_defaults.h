/***************************************************************************
 * 31-12-2010 LT                                                           *
 *                                                                         *
 * The present header defines all the default values used with the KNTarc  *
 * structure. In particular the "DONT_CARE" and "STR_DONT_CARE" values.    *
 * 1. Default flags for the structure                                      *
 *  - arc_type                                                             *
 *  - closure                                                              *
 *  - simplification                                                       *
 * 2. Default I/O hdf5 attributes and names.                               *
 * 3. Default entries for knot matrix.                                     *
 * ************************************************************************/

#ifndef HDR_KNT_DEF
#define HDR_KNT_DEF

#define DONT_CARE  -2
#define STR_DONT_CARE "----"

#define FALSE 0

#define TRUE 1

#define PI (3.141592653589793)

#include "KNT_table.h"

/*
 * arc_type identifiers
 */
#define ARC_ID_RING    'R'  /*whole ring                                       */
#define ARC_ID_LIN     'L'  /*a linear chain                                   */
#define ARC_ID_ANY     'A'  /*a generic arc                                    */
#define ARC_ID_PCOMP   'O'  /*prime     component                              */
#define ARC_ID_ST      'T'  /*shortest topological entanglement                */
#define ARC_ID_STU     'V'  /*shortest topological entanglenemnt. no Unkn check*/
#define ARC_ID_SK      'S'  /*shortest knotted arc (possibly ephemeral)        */
#define ARC_ID_SKU     'U'  /*shortest knotted arc without unknottednes check  */
#define ARC_ID_SCK     'C'  /*shortest continuosly knotted arc (non ephemeral) */

/****Closure schemes keywords*********/
/*
 * The first character of each string is used
 * as idenfitifier!
 */

#define NONE            "None"                /* no closure, linear chain.        */
#define RING            "Ring"                /* no need to close, already a ring */
#define BRIDGECLOSURE   "Bridge"
#define QHULLCLOSURE    "Qhull"
#define QHULLCLOSUREHYB "Hybrid"
#define RADIALCLOSURE   "Radial"
#define STCHCLOSURE     "Stochastic"

/****Simplification schemes keywords*****/
#define SIMPNONE        "None"
#define SIMPRECT        "Rectification"
#define SIMPTOPO        "Rectification and analysis"
/****HDF5 STANDARD i/o objects names***/

#define KNT_COORDNAME  "coord"
#define KNT_KNTMATNAME "knot_matrix"
#define KNT_IDXNAME    "indices"

#define KNT_TABLENAME "properties"
#define KNT_OUTFIELDS  18
#define STR_OUT_MAXLEN 64


/*****Precision************************/
#define KNT_EPSIL ( 0.0000001 )

#endif /*HDR_KNT_DEF*/

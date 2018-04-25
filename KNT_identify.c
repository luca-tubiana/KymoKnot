#include "KNT_table.h"
#include "KNT_identify.h"
#include "KNT_simplify.h"
#include "Alexander.h"
#include "my_memory.h"
#include <stdlib.h>

const KNTid _ktable[KTABLE_LEN]=KNTadets_KNTLIST;
const char * _rolfsentable[KTABLE_LEN]=ROLFSEN_TABLE;
const KNTid KNTid_DEFAULT  =_KNTid_DEFAULT;

KNTID_wspace * KNTID_wspace_init ( KNTID_ws_var *init)
{
	KNTid knt_table[KTABLE_LEN]=KNTadets_KNTLIST;
	KNTID_wspace *ws = malloc(sizeof(KNTID_wspace));
	if (ws ==NULL )
	{
		failed("In KNTID_wspace_init.\nUnable to allocate memory for knot determination\n");
	}
	ws->buffer_dim=init->buffer_dim;
	ws->alex_dim=init->alex_dim;
	ws->known_knots=&_ktable;
	//if (ws->known_knots==NULL )
	//{
	//	failed("In KNTID_wspace_init.\nUnable to allocate memory for knots table\n");
	//}
	//for(int i=0;i<KTABLE_LEN;i++) { ws->known_knots[i]=knt_table[i]; }
	ws->target_knot	=KNTid_DEFAULT;
	ws->coord_buffer=d2t(init->buffer_dim,3);
	ws->alx_wspace	=ALX_wspace_alloc(init->alex_dim);
	return ws;
}

void KNTID_free_wspace ( KNTID_wspace *ws)
{
	if (NULL != ws)
	{
		if ( NULL != ws->alx_wspace ) { ALX_free_wspace	(ws->alx_wspace		);}
		if ( NULL != ws->coord_buffer){ free_d2t 				(ws->coord_buffer	);}
		free						(ws);
	}
}

void 	KNTID_set_target_knot 			(	KNTID_wspace *ws, KNTid target	)
{
	ws->target_knot=target;
}

void 	KNTID_unset_target_knot		(	KNTID_wspace *ws	)
{
	ws->target_knot=KNTid_DEFAULT;
}

KNTid KNTID_identify_knot ( KNTarc *knt_ptr, KNTID_wspace *kid_ws )
{
	int    N_simp_coord;
	double ** simp_coord;
	int    determinant;
	KNTid  k_type;//=KNTid_DEFAULT;
	KNTid  k_Un={0,{1,1}};
	int    t[2] = {-1,-2};
	int    is_alx_allocated = FALSE;

	// check knt_ptr is correctly initialized
	if( knt_ptr->is_init != 1 || knt_ptr->flag_len != 1 || knt_ptr->coord == NULL )
	{
		failed ( "KNTLknot_determination. knt_ptr is not correctly initialized!\n");
	}

	// check if Alexander determinants where already computed. If so,
	// simply determine the knot type (see TABLE in KNT_defaults.h)
	// and exit.
	KNTarc_GETif(knt_ptr,knot_type,k_type,k_type.k_id,KNTid);
	if ( k_type.k_id != DONT_CARE)
	{
		return k_type;
	}

	// simplify chain prior to Alexander determinants computation
	N_simp_coord = knt_ptr->len;
	if 	( kid_ws->coord_buffer == NULL ) 	{
		simp_coord = d2t( N_simp_coord, 3 );
	} else if (N_simp_coord>kid_ws->buffer_dim) {
		free_d2t(kid_ws->coord_buffer);
		kid_ws->buffer_dim=N_simp_coord;
		kid_ws->coord_buffer=d2t(kid_ws->buffer_dim,3);
		simp_coord = kid_ws->coord_buffer;
	} else {
		simp_coord = kid_ws->coord_buffer;
	}
	//chain_remove_beads_new (knt_ptr->len, knt_ptr->coord, &N_simp_coord, simp_coord, NULL, DONT_CARE);
	chain_remove_beads_w_shuffle_nostride (knt_ptr->len, knt_ptr->coord, &N_simp_coord, simp_coord);

	// no knot can be formed with less than 5 segments
	if	( N_simp_coord < 4 ) { k_type=k_Un; }
	else
	{
		if(kid_ws->alx_wspace == NULL)
		{
			is_alx_allocated = TRUE ;
			kid_ws->alx_wspace = ALX_wspace_alloc ( knt_ptr->len );
		}
		determinant = ALX_alex_generict ( N_simp_coord, simp_coord, 2, t, k_type.Adets, kid_ws->alx_wspace);
		//target knot is the one we want to find in a search and can be an
		//untabulated knot. It is initialized to {DONT_CARE, {DONT_CARE,DONT_CARE}},
		//if set to some value, it is checked first, both to enable the localization
		//of untabulated knots and to speed it up when localizing a tabulated knot.
		if ( 	kid_ws->target_knot.k_id != DONT_CARE 				&&
					k_type.Adets[0]==kid_ws->target_knot.Adets[0] &&
					k_type.Adets[1]==kid_ws->target_knot.Adets[1]   )
		{
			k_type.k_id=kid_ws->target_knot.k_id;
		}
		else
		{
			k_type.k_id=K_UNKNWN;
			for ( int i = 0 ; i < KTABLE_LEN; i++ )
			{
				if(k_type.Adets[0] == kid_ws->known_knots[i].Adets[0] && k_type.Adets[1] == kid_ws->known_knots[i].Adets[1])
				{
					k_type.k_id=kid_ws->known_knots[i].k_id;
					break;
				}
			}
		}
	}
	KNTarc_SET_value(knt_ptr,knot_type,k_type,KNTid);
	//free allocated memory
	if 	( kid_ws->coord_buffer == NULL) { free_d2t(simp_coord); }
	if	( is_alx_allocated 						) { ALX_free_wspace( kid_ws->alx_wspace );}

	return k_type;
}

KNTid KNTID_get_knot_from_id (int k_type)
{
	if(k_type>=0 && k_type < KTABLE_LEN)
		return _ktable[k_type];
	else
		return KNTid_DEFAULT;
}

void KNTID_get_rolfsen (char *rolf_id,int bfs, KNTid K)
{
	if(bfs<64) { return; }
	if(K.k_id >=0 && K.k_id<KTABLE_LEN)
		sprintf(rolf_id,"%s",_rolfsentable[K.k_id]);
	else
		sprintf(rolf_id,"??");
	return;
}

void KNTID_print_knot (char *knot_ids,int bfs, KNTid K)
{
	if(bfs<64) { failed("KNTID_print_knot: print buffer too small"); }
	if(K.k_id >=0 && K.k_id<KTABLE_LEN)
	{
		sprintf(knot_ids,"%d %d\t%s\t",K.Adets[0],K.Adets[1],_rolfsentable[K.k_id]);
	}
	else
	{
		sprintf(knot_ids,"%d %d\t??\t",K.Adets[0],K.Adets[1]);
	}
	return;
}
void KNTID_print_unknot (char *knot_ids,int bfs)
{
	if(bfs<64) { failed("KNTID_print_unknot: print buffer too small"); }
	sprintf(knot_ids,"%d %d\t%s",_ktable[K_Un].Adets[0],_ktable[K_Un].Adets[1],_rolfsentable[K_Un]);
	return;
}

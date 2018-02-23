#ifndef __H_MANAGER
#define __H_MANAGER
#define _VERSION_ "1.5"

#define BU  0
#define TD  1
#define UNS 2
#define N_SEARCHES 3
#define MEMLEN 1000

#include "KNT_defaults.h"
#include "KNT_arc.h"
#include "KNT_lib.h"
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

typedef struct _SearchManager_t {
	int st_p;
	int end_p;
	int S;
	KNTarc (*ClsFnc_ptr) ( KNTarc * ring_ptr, int start, int end );
 	void (*LocFnc_ptr)
		( KNTarc * knt_ptr, KNTarc * knt_rect, int st_p, int end_p,
			KNTarc (*close_subchain) ( KNTarc *, int, int ), KNTID_wspace *ws );
  char arc_id;
  char fout_prefix[16];
  char fout_expl  [128];
  char fout_hdr   [512];
	FILE *fout;
} searchManager_t;
//typedef struct _SearchManager_t searchManager_t;

struct param_t {
	// "private"
	int _min_stride;
	int _simp_sweeps;
	// "public" (can be modified by command line arguments)
  char filename[1024];
	char fname_prev_search[1024];
	FILE *fin;
	FILE *fin_prev_search;
	int memlen;
	int seed;
	int max_stride;
	int arc_start;
	int arc_end;
	int print_conf; 
	char closure_type;
	int search_type[N_SEARCHES];
	searchManager_t search[N_SEARCHES];
	// non-optional
	int counter;
	KNTID_wspace	*kntid_ws;
	//flags
	int f_arc_start,f_arc_end,f_prev_search,f_max_stride;
};

void set_default_behaviour	(struct param_t *param);
void read_command_line 			(struct param_t *param, int argc, char **argv);
void set_search_brackets_linear (struct param_t *param, int cnt, int arc_len);
void set_search_brackets_ring 	(struct param_t *param, int cnt, int arc_len);
void settings2string 		 		(char *string, struct param_t *param);
void settings2stderr 				(char *string, struct param_t *param );
void searchManagers_init 		(struct param_t *param, char *settingsString);
void print_search_results_linear (KNTarc *knt_ptr, searchManager_t *sM,int cnt, struct param_t *param);
void print_search_results_ring   (KNTarc *knt_ptr, searchManager_t *sM,int cnt, struct param_t *param);
int  get_idx_rect_chain  		(KNTarc *knt_rect,int idx_orig);
void kymoknot_initialize		(struct param_t *param,int argc, char **argv);
void kymoknot_terminate 		(struct param_t *param);
void print_help();

#endif //__H_MANAGER

typedef struct param_t {
	// "private"
	int _min_stride;
	int _simp_sweeps;
	// "public" (can be modified by command line arguments)
	char filename[1024];
	FILE *fin;
	int memlen;
	int seed;
	int max_stride;
	int arc_start;
	int arc_end;
	int print_conf;
	char closure_type;
	int search_type[N_SEARCHES];
	searchManager_t search[N_SEARCHES];
} kloc_par;

typedef struct {
	int memlen;
	int seed; int f_seed;
	int max_stride; int f_max_stride;
	int arc_start; 	int f_arc_start;
	int arc_end;  	int f_arc_end;
	int print_conf;
	char *closure_type;
	int reset_searches;
	int search_type[N_SEARCHES];
} kloc_opt;

kloc_opt DEFAULT_OPTIONS={
	DONT_CARE, 		//memlen
	DONT_CARE,FALSE,		//seed
	DONT_CARE,FALSE,		//max_stride
	DONT_CARE,FALSE, 		//arc_start
	DONT_CARE,FALSE,		//arc_end
	FALSE,		//print_conf
	STR_DONT_CARE,		//cls_type
	FALSE,								//reset searches
	{FALSE,FALSE,FALSE}}; //search_type



kloc_par * kloc_par_default()
{
	kloc_par *param=(kloc_par*)malloc(sizeof(kloc_par));
	param->_min_stride				=2;
	param->_simp_sweeps				=4;
	//modifiable by options
	param->arc_start 					=0;
	param->arc_end		 				=DONT_CARE;
	param->max_stride					=0;
	param->print_conf 				=FALSE;
	param->memlen 						=MEMLEN;
	param->closure_type 			=QHULLCLOSUREHYB[0];
	param->seed								=time(NULL)+getpid();
	param->search_type[BU]		=TRUE;
	param->search_type[TD]		=TRUE;
	param->search_type[UNS]		=FALSE;
	param->search[BU] 				=BUsearch_DEFAULT;
	param->search[TD] 				=TDsearch_DEFAULT;
	param->search[UNS] 				=UNSsearch_DEFAULT;
	return param;
}

void kloc_par_free(kloc_par *param)
{
	if(param !=NULL) {
		free(param);
	}
}

kloc_opt * kloc_opt_default()
{
	kloc_opt *options=(kloc_opt*)malloc(sizeof(kloc_opt));
	options->memlen				=DONT_CARE;
	options->seed					=DONT_CARE;
	options->max_stride		=DONT_CARE;
	options->arc_start		=DONT_CARE;
	options->arc_end			=DONT_CARE;
	options->f_seed				=FALSE;
	options->f_max_stride	=FALSE;
	options->f_arc_start	=FALSE;
	options->f_arc_end		=FALSE;
	options->print_conf		=FALSE;
	options->reset_searches=FALSE;
	options->closure_type =STR_DONT_CARE;
	options->search_type 	={DONT_CARE,DONT_CARE,DONT_CARE};
	return options;
}

void kloc_opt_free(kloc_par *options)
{
	if(options !=NULL) {
		free(options);
	}
}

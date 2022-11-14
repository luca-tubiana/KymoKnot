#include "KNT_io.h"
#include "my_geom.h"
#include "my_memory.h"
#include "messages.h"
#include <string.h>
#include <stdlib.h>

KNTarc *  KNTIOread_ring(  FILE * fp )
{
  int i, j , length;
  double ** buffer;
  KNTarc * knt_ptr;
  size_t len =2048;
  ssize_t read;
  char *line = NULL;
  char *l_ptr;
  char *col[3];
  char *token;
  char *saveptr;
  char string[2048];

  line = (char * ) malloc ( len );
  if( (read = getline(&line,&len,fp)) == -1 )
  {
    free ( line );
    return NULL;
  }
  if ( read + 1 > 2048 )
  {
    failed (" Input strings are longer than 2048 bytes. Recompile me\n");
  }
  strncpy(string,line,read+1);
  token = strtok_r(string," ",&saveptr);
  length = atoi(token);
  free ( line );
  line = NULL;

  buffer =  d2t(length,3);

  for ( i = 0; i < length ; i++ ) 
  {
    len = 2048;
    line = (char * ) malloc ( len );
    read = getline (&line,&len,fp);
    if ( read + 1 > 2048 )
    {
      free ( line );
      failed (" Input strings are longer than 2048 bytes. Recompile me\n");
    }
    strncpy(string,line,read+1);
    free ( line );
    if ( read <0 ) 
    {
      free ( line );
      free_d2t(buffer);
      failed("failed to read line in input file");
    }
    //done reading the line, let's separate it into 3 columns.
    j = 0;
    l_ptr = string;
    for(;;)
    {
      token = strtok_r(l_ptr," ",&saveptr);
      l_ptr = NULL;
      if (token == NULL )
      {
        break;
      }
      if ( j >= 3 )
      {
        free_d2t(buffer);
        failed("Too many columns in input file");
      }
      col[j] = (char * ) malloc(strlen(token)+1);
      strcpy ( col[j], token);
      j++;
    }
    if (j < 3 )
    {
      fprintf(stderr,"Jammed column:\n");
      for ( int k = 0 ; k< j ;k++ )
      {
        fprintf(stderr,"%s\t",col[k]);
      }
      fprintf(stderr,"\n");
      free ( line );
      failed("Jammed columns in input file");
    }
    for ( j=0;j<3 ;j++)
    {
      buffer[i][j] = atof(col[j]);
      free ( col[j] );
    }
  }

  if ( dist_d (buffer[0],buffer[length-1],3)> 1.0e-6)
  {
    failed("ERROR. first and last node do not coincide\n");
  }

  /* inizialize pointer, allocate memory */
  knt_ptr = KNTinit_ptr();
  /*
   * Set values in knt_ptr structure for an 
   * unsimplified ring of length "length-1".
   */
  KNTarc_SET_value(knt_ptr,len,length-1,int);
  KNTarc_SET_value(knt_ptr,start,0,int);
  KNTarc_SET_value(knt_ptr,end,length-1,int);
  KNTarc_SET_value(knt_ptr,arc_type,ARC_ID_RING,char);
  strncpy(knt_ptr->closure,RING,strlen(RING));
  strncpy(knt_ptr->simplification,SIMPNONE,strlen(SIMPNONE));
  /*allocate memory for ring coordinates */
  knt_ptr->coord = d2t ( knt_ptr->len, 3 );
  knt_ptr->index = i1t ( knt_ptr->len    );

  for ( i = 0; i < knt_ptr->len ; i++ ) 
  {
    for ( j = 0 ; j < 3 ; j++ ) 
    {
      knt_ptr->coord[i][j] = buffer[i][j];
    }
    knt_ptr->index[i] = i;
  }

  free_d2t(buffer);
  return knt_ptr;
}

KNTarc *  KNTIOread_linear(  FILE * fp )
{
  int i, j , length;
  double ** buffer;
  KNTarc * knt_ptr;
  size_t len =2048;
  ssize_t read;
  char *line = NULL;
  char *l_ptr;
  char *col[3];
  char *token;
  char *saveptr;
  char string[2048];

  line = (char * ) malloc ( len );
  if( (read = getline(&line,&len,fp)) == -1 )
  {
    free ( line );
    return NULL;
  }
  if ( read + 1 > 2048 )
  {
    failed (" Input strings are longer than 2048 bytes. Recompile me\n");
  }
  strncpy(string,line,read+1);
  token = strtok_r(string," ",&saveptr);
  length = atoi(token); //Get the length of the chain
  free ( line );
  line = NULL;

  buffer =  d2t(length,3);

  for ( i = 0; i < length ; i++ ) 
  {
    len = 2048;
    line = (char * ) malloc ( len );
    read = getline (&line,&len,fp);
    if ( read + 1 > 2048 )
    {
      free ( line );
      failed (" Input strings are longer than 2048 bytes. Recompile me\n");
    }
    strncpy(string,line,read+1);
    //free ( line );
    if ( read <0 ) 
    {
      free ( line );
      free_d2t(buffer);
      failed("failed to read line in input file");
    }
    //done reading the line, let's separate it into 3 columns.
    j = 0;
    l_ptr = string;
    for(;;)
    {
      token = strtok_r(l_ptr," ",&saveptr);
      l_ptr = NULL;
      if (token == NULL )
      {
        break;
      }
      if ( j >= 3 )
      {
        free_d2t(buffer);
        failed("Too many columns in input file");
      }
      col[j] = (char * ) malloc(strlen(token)+1);
      strcpy ( col[j], token);
      j++;
    }
    if (j < 3 )
    {
      fprintf(stderr,"Jammed column:\n");
      for ( int k = 0 ; k< j ;k++ )
      {
        fprintf(stderr,"%s\t",col[k]);
      }
      fprintf(stderr,"\n");
      free ( line );
      failed("Jammed columns in input file");
    }
    for ( j=0;j<3 ;j++)
    {
      buffer[i][j] = atof(col[j]);
      free ( col[j] );
    }

    free ( line );
  }

  if ( dist_d (buffer[0],buffer[length-1],3)< 1.0e-6)
  {
    failed("\nERROR. first and last node do coincide within 1.0e-6,\n we are reading a ring not a linear chain!\n");
  }

  /* inizialize pointer, allocate memory */
  knt_ptr = KNTinit_ptr();
  /*
   * Set values in knt_ptr structure for an 
   * unsimplified chain of length "length".
   */
  KNTarc_SET_value(knt_ptr,len,length,int);
  KNTarc_SET_value(knt_ptr,start,0,int);
  KNTarc_SET_value(knt_ptr,end,length-1,int);
  KNTarc_SET_value(knt_ptr,arc_type,ARC_ID_LIN,char);
  strncpy(knt_ptr->closure,NONE,strlen(NONE));
  strncpy(knt_ptr->simplification,SIMPNONE,strlen(SIMPNONE));
  /*allocate memory for ring coordinates */
  knt_ptr->coord = d2t ( knt_ptr->len, 3 );
  knt_ptr->index = i1t ( knt_ptr->len    );

  for ( i = 0; i < knt_ptr->len ; i++ ) 
  {
    for ( j = 0 ; j < 3 ; j++ ) 
    {
      knt_ptr->coord[i][j] = buffer[i][j];
    }
    knt_ptr->index[i] = i;
  }

  free_d2t(buffer);
  return knt_ptr;
}

KNTarc *  KNTIOread_ring_lammps_version(  FILE * fp )
{
    int i, j , length;
    double ** buffer;
    KNTarc * knt_ptr;
    size_t len =2048;
    ssize_t read;
    char *line = NULL;
    char *l_ptr;
    char *col[3];
    char *token;
    char *saveptr;
    char string[2048];

    line = (char * ) malloc ( len );
    if( (read = getline(&line,&len,fp)) == -1 )
    {
        free ( line );
        return NULL;
    }
    if ( read + 1 > 2048 )
    {
        failed (" Input strings are longer than 2048 bytes. Recompile me\n");
    }
    strncpy(string,line,read+1);
    token = strtok_r(string," ",&saveptr);
    length = atoi(token);
    free ( line );
    line = NULL;

    buffer =  d2t(length,3);
    read = getline (&line,&len,fp);//skip one line in lammps file

    for ( i = 0; i < length ; i++ )
    {
        len = 2048;
        line = (char * ) malloc ( len );
        read = getline (&line,&len,fp);
        if ( read + 1 > 2048 )
        {
            free ( line );
            failed (" Input strings are longer than 2048 bytes. Recompile me\n");
        }
        strncpy(string,line,read+1);
        free ( line );
        if ( read <0 )
        {
            free ( line );
            free_d2t(buffer);
            failed("failed to read line in input file");
        }
        //done reading the line, let's separate it into 3 columns.
        j = 0;
        l_ptr = string;
        for(;;)
        {
            token = strtok_r(l_ptr," ",&saveptr);
            l_ptr = NULL;
            if (token == NULL )
            {
                break;
            }
            if ( j >= 4 )
            {
                free_d2t(buffer);
                failed("Too many columns in input file");
            }
            col[j] = (char * ) malloc(strlen(token)+1);
            strcpy ( col[j], token);
            j++;
        }
        // skip the test
//        if (j < 4 )
//        {
//            fprintf(stderr,"Jammed column:\n");
//            for ( int k = 0 ; k< j ;k++ )
//            {
//                fprintf(stderr,"%s\t",col[k]);
//            }
//            fprintf(stderr,"\n");
//            free ( line );
//            failed("Jammed columns in input file");
//        }
        for ( j=0;j<3 ;j++)
        {
            buffer[i][j] = atof(col[j+1]);
            free ( col[j+1] );
        }
    }
    if ( dist_d (buffer[0],buffer[length-1],3)< 1.2*dist_d (buffer[0],buffer[1],3))
    {
        failed("ERROR. first and last node do not coincide\n");
    }

    /* inizialize pointer, allocate memory */
    knt_ptr = KNTinit_ptr();
    /*
     * Set values in knt_ptr structure for an
     * unsimplified ring of length "length-1".
     */
    KNTarc_SET_value(knt_ptr,len,length-1,int);
    KNTarc_SET_value(knt_ptr,start,0,int);
    KNTarc_SET_value(knt_ptr,end,length-1,int);
    KNTarc_SET_value(knt_ptr,arc_type,ARC_ID_RING,char);
    strncpy(knt_ptr->closure,RING,strlen(RING));
    strncpy(knt_ptr->simplification,SIMPNONE,strlen(SIMPNONE));
    /*allocate memory for ring coordinates */
    knt_ptr->coord = d2t ( knt_ptr->len, 3 );
    knt_ptr->index = i1t ( knt_ptr->len    );

    for ( i = 0; i < knt_ptr->len ; i++ )
    {
        for ( j = 0 ; j < 3 ; j++ )
        {
            knt_ptr->coord[i][j] = buffer[i][j];
        }
        knt_ptr->index[i] = i;
    }

    free_d2t(buffer);
    return knt_ptr;
}

KNTarc *  KNTIOread_linear_lammps_version(  FILE * fp )
{
    int i, j , length;
    double ** buffer;
    KNTarc * knt_ptr;
    size_t len =2048;
    ssize_t read;
    char *line = NULL;
    char *l_ptr;
    char *col[3];
    char *token;
    char *saveptr;
    char string[2048];

    line = (char * ) malloc ( len );
    if( (read = getline(&line,&len,fp)) == -1 )
    {
        free ( line );
        return NULL;
    }
    if ( read + 1 > 2048 )
    {
        failed (" Input strings are longer than 2048 bytes. Recompile me\n");
    }
    strncpy(string,line,read+1);
    token = strtok_r(string," ",&saveptr);
    length = atoi(token); //Get the length of the chain
    free ( line );
    line = NULL;

    buffer =  d2t(length,3);
    read = getline (&line,&len,fp); // to escape the line of the LAMMPS file
    for ( i = 0; i < length ; i++ )
    {
        len = 2048;
        line = (char * ) malloc ( len );
        read = getline (&line,&len,fp);
        if ( read + 1 > 2048 )
        {
            free ( line );
            failed (" Input strings are longer than 2048 bytes. Recompile me\n");
        }
        strncpy(string,line,read+1);
        //free ( line );
        if ( read <0 )
        {
            free ( line );
            free_d2t(buffer);
            failed("failed to read line in input file");
        }
        //done reading the line, let's separate it into 3 columns.
        j = 0;
        l_ptr = string;
        for(;;)
        {
            token = strtok_r(l_ptr," ",&saveptr);
            l_ptr = NULL;
            if (token == NULL )
            {
                break;
            }
            if ( j >= 4 )
            {
                free_d2t(buffer);
                failed("Too many columns in input file");
            }
            col[j] = (char * ) malloc(strlen(token)+1);
            strcpy ( col[j], token);
            j++;
        }
// though it should work but when j=4,it will run, I do not know why
//        if (j < 4 )
//        {
//            fprintf(stderr,"Jammed column:\n");
//            for ( int k = 0 ; k< j ;k++ )
//            {
//                fprintf(stderr,"%s\t",col[k]);
//            }
//            fprintf(stderr,"\n");
//            free ( line );
//            failed("Jammed columns in input file");
//        }
        for ( j=0;j<3 ;j++)
        {
            buffer[i][j] = atof(col[j+1]);
            free ( col[j+1] );
        }

        free ( line );
    }
// just based on we set 1 and end to a circle but they are not the same points
    if ( dist_d (buffer[0],buffer[length-1],3)> 1.0e-6)
    {
        failed("\nERROR. first and last node do coincide within 1.0e-6,\n we are reading a ring not a linear chain!\n");
    }

    /* inizialize pointer, allocate memory */
    knt_ptr = KNTinit_ptr();
    /*
     * Set values in knt_ptr structure for an
     * unsimplified chain of length "length".
     */
    KNTarc_SET_value(knt_ptr,len,length,int);
    KNTarc_SET_value(knt_ptr,start,0,int);
    KNTarc_SET_value(knt_ptr,end,length-1,int);
    KNTarc_SET_value(knt_ptr,arc_type,ARC_ID_LIN,char);
    strncpy(knt_ptr->closure,NONE,strlen(NONE));
    strncpy(knt_ptr->simplification,SIMPNONE,strlen(SIMPNONE));
    /*allocate memory for ring coordinates */
    knt_ptr->coord = d2t ( knt_ptr->len, 3 );
    knt_ptr->index = i1t ( knt_ptr->len    );

    for ( i = 0; i < knt_ptr->len ; i++ )
    {
        for ( j = 0 ; j < 3 ; j++ )
        {
            knt_ptr->coord[i][j] = buffer[i][j];
        }
        knt_ptr->index[i] = i;
    }

    free_d2t(buffer);
    return knt_ptr;
}

void  KNTIOprint_arc  ( FILE *out, KNTarc * knt_ptr, int start, int end)
{
	int i;
	int klen;
  klen = ( end > start ) ? end - start : end + knt_ptr->len - start;
	fprintf(out,"%d\n", klen);
	if(end>start)
	{
		for (i=start;i<end;i++)
		{
			fprintf(out,"%lf %lf %lf\n",
					knt_ptr->coord[i][0],
					knt_ptr->coord[i][1],
					knt_ptr->coord[i][2]);
		}
	}
	else
	{
		for (i=start;i<knt_ptr->len;i++)
		{
			fprintf(out,"%lf %lf %lf\n",
					knt_ptr->coord[i][0],
					knt_ptr->coord[i][1],
					knt_ptr->coord[i][2]);
		}
		for(i=0;i<end;i++)
		{
			fprintf(out,"%lf %lf %lf\n",
					knt_ptr->coord[i][0],
					knt_ptr->coord[i][1],
					knt_ptr->coord[i][2]);
		}
	}
}
void  KNTIOprint_ring  ( FILE *out, KNTarc * knt_ptr)
{
	int i;
	fprintf(out,"%d\n", knt_ptr->len+1);
	for (i=0;i<knt_ptr->len;i++)
	{
		fprintf(out,"%lf %lf %lf\n",
				knt_ptr->coord[i][0],
				knt_ptr->coord[i][1],
				knt_ptr->coord[i][2]);
	}
		fprintf(out,"%lf %lf %lf\n",
				knt_ptr->coord[0][0],
				knt_ptr->coord[0][1],
				knt_ptr->coord[0][2]);
}
void  KNTIOprint_linear  ( FILE *out, KNTarc * knt_ptr )
{
	int i;
	fprintf(out,"%d\n", knt_ptr->len);
	for (i=0;i<knt_ptr->len;i++) {
		fprintf(out,"%lf %lf %lf\n",
				knt_ptr->coord[i][0],
				knt_ptr->coord[i][1],
				knt_ptr->coord[i][2]);
	}
}

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_memory.h"
#include "messages.h"

FILE **F2t (int n1)
{
  FILE **p;
  if ((p = (FILE **) malloc ((size_t) n1 * sizeof (FILE *))) == NULL)
      failed ("F2t: failed n1");
  return p;
}

FILE ***F3t (int n1, int n2)
{
  FILE ***p;
  int i;
  if ((p = (FILE ***) malloc ((size_t) n1 * sizeof (FILE **))) == NULL)
      failed ("F3t: failed n1");
  if ((p[0] = (FILE **) malloc ((size_t) n1 * n2 * sizeof (FILE *))) == NULL)
      failed ("F3t: failed n2");
  for (i = 0; i < n1 - 1; i++)
    p[i + 1] = p[i] + n2;
  return p;
}
char *c1t (int n1)
{
  char *p;
  if ((p = (char *) malloc ((size_t) n1 * sizeof (char))) == NULL)
      failed ("c1t: failed");
  return p;
}

char **c2t (int n1, int n2)
{
  char **p;
  int i;
  if ((p = (char **) malloc ((size_t) n1 * sizeof (char *))) == NULL)
      failed ("c2t: failed n1");
  if ((p[0] = (char *) malloc ((size_t) n1 * n2 * sizeof (char))) == NULL)
      failed ("c2t: failed n2");
  for (i = 0; i < n1 - 1; i++)
    p[i + 1] = p[i] + n2;
  return p;
}

char ***c3t (int n1, int n2, int n3)
{
  char ***p;
  int i, j;
  if ((p = (char ***) malloc ((size_t) n1 * sizeof (char **))) == NULL)
      failed ("c3t: failed n1");
  if ((p[0] = (char **) malloc ((size_t) n1 * n2 * sizeof (char *))) == NULL)
      failed ("c3t: failed n2");
  if ((p[0][0] = (char *) malloc ((size_t) n1 * n2 * n3 * sizeof (char))) == NULL)
      failed ("c3t: failed n3");
  for (i = 0; i < n2 - 1; i++)
    p[0][i + 1] = p[0][i] + n3;
  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      for (j = 0; j < n2 - 1; j++)
	p[i + 1][j + 1] = p[i + 1][j] + n3;
    }
  return p;
}


char ****c4t (int n1, int n2, int n3, int n4)
{
  char ****p, *a;
  int i, j, k;
  if ((p = (char ****) malloc ((size_t) n1 * sizeof (char ***))) == NULL)
      failed ("c4t: failed n1");
  if ((p[0] = (char ***) malloc ((size_t) n1 * n2 * sizeof (char **))) == NULL)
      failed ("c4t: failed n2");
  if ((p[0][0] = (char **) malloc ((size_t) n1 * n2 * n3 * sizeof (char *))) == NULL)
      failed ("c4t: failed n3");
  if ((p[0][0][0] = (char *) malloc ((size_t) n1 * n2 * n3 * n4 * sizeof (char ))) == NULL)
      failed ("c4t: failed n4");

  for (i = 0; i < n3 - 1; i++)
    p[0][0][i + 1] = p[0][0][i] + n4;

  for (i = 0; i < n2 - 1; i++)
    {
      p[0][i + 1] = p[0][i] + n3;
      p[0][i + 1][0] = p[0][i][0] + n3 * n4;
      for (j = 0; j < n3 - 1; j++)
	p[0][i + 1][j + 1] = p[0][i + 1][j] + n4;
    }

  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      p[i + 1][0][0] = p[i][0][0] + n2 * n3 * n4;

      for (j = 0; j < n3 - 1; j++)
	p[i + 1][0][j + 1] = p[i + 1][0][j] + n4;

      for (j = 0; j < n2 - 1; j++)
	{
	  p[i + 1][j + 1] = p[i + 1][j] + n3;
	  p[i + 1][j + 1][0] = p[i + 1][j][0] + n3 * n4;
	  for (k = 0; k < n3 - 1; k++)
	    p[i + 1][j + 1][k + 1] = p[i + 1][j + 1][k] + n4;
	}
    }

  for (i = 0, a = p[0][0][0]; i < n1 * n2 * n3 * n4; i++)
    *a++ = 0.0;

  return p;
}




short *s1t (int n1)
{
  short *p, *a;
  int i;
  if ((p = (short *) malloc ((size_t) n1 * sizeof (short))) == NULL)
      failed ("s1t: failed");
  for (i = 0, a = p; i < n1; i++)
    *a++ = 0;
  return p;
}

short **s2t (int n1, int n2)
{
  short **p, *a;
  int i;
  if ((p = (short **) malloc ((size_t) n1 * sizeof (short *))) == NULL)
      failed ("s2t: failed n1");
  if ((p[0] = (short *) malloc ((size_t) n1 * n2 * sizeof (short))) == NULL)
      failed ("s2t: failed n2");
  for (i = 0; i < n1 - 1; i++)
    p[i + 1] = p[i] + n2;
  for (i = 0, a = p[0]; i < n1 * n2; i++)
    *a++ = 0;
  return p;
}

short ***s3t (int n1, int n2, int n3)
{
  short ***p, *a;
  int i, j;
  if ((p = (short ***) malloc ((size_t) n1 * sizeof (short **))) == NULL)
      failed ("s3t: failed n1");
  if ((p[0] = (short **) malloc ((size_t) n1 * n2 * sizeof (short *))) == NULL)
      failed ("s3t: failed n2");
  if ((p[0][0] = (short *) malloc ((size_t) n1 * n2 * n3 * sizeof (short))) == NULL)
      failed ("s3t: failed n3");
  for (i = 0; i < n2 - 1; i++)
    p[0][i + 1] = p[0][i] + n3;
  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      for (j = 0; j < n2 - 1; j++)
	p[i + 1][j + 1] = p[i + 1][j] + n3;
    }
  for (i = 0, a = p[0][0]; i < n1 * n2 * n3; i++)
    *a++ = 0;
  return p;
}

short ****s4t (int n1, int n2, int n3, int n4)
{
  short ****p, *a;
  int i, j, k;
  if ((p = (short ****) malloc ((size_t) n1 * sizeof (short ***))) == NULL)
      failed ("s4t: failed n1");
  if ((p[0] = (short ***) malloc ((size_t) n1 * n2 * sizeof (short **))) == NULL)
      failed ("s4t: failed n2");
  if ((p[0][0] = (short **) malloc ((size_t) n1 * n2 * n3 * sizeof (short *))) == NULL)
      failed ("s4t: failed n3");
  if ((p[0][0][0] = (short *) malloc ((size_t) n1 * n2 * n3 * n4 * sizeof (short ))) == NULL)
      failed ("s4t: failed n4");

  for (i = 0; i < n3 - 1; i++)
    p[0][0][i + 1] = p[0][0][i] + n4;

  for (i = 0; i < n2 - 1; i++)
    {
      p[0][i + 1] = p[0][i] + n3;
      p[0][i + 1][0] = p[0][i][0] + n3 * n4;
      for (j = 0; j < n3 - 1; j++)
	p[0][i + 1][j + 1] = p[0][i + 1][j] + n4;
    }

  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      p[i + 1][0][0] = p[i][0][0] + n2 * n3 * n4;

      for (j = 0; j < n3 - 1; j++)
	p[i + 1][0][j + 1] = p[i + 1][0][j] + n4;

      for (j = 0; j < n2 - 1; j++)
	{
	  p[i + 1][j + 1] = p[i + 1][j] + n3;
	  p[i + 1][j + 1][0] = p[i + 1][j][0] + n3 * n4;
	  for (k = 0; k < n3 - 1; k++)
	    p[i + 1][j + 1][k + 1] = p[i + 1][j + 1][k] + n4;
	}
    }

  for (i = 0, a = p[0][0][0]; i < n1 * n2 * n3 * n4; i++)
    *a++ = 0.0;

  return p;
}





int *i1t (int n1)
{
  int *p, *a;
  int i;
  if ((p = (int *) malloc ((size_t) n1 * sizeof (int))) == NULL)
      failed ("i1t: failed");
  for (i = 0, a = p; i < n1; i++)
    *a++ = 0;
  return p;
}

int **i2t (int n1, int n2)
{
  int **p, *a;
  int i;
  if ((p = (int **) malloc ((size_t) n1 * sizeof (int *))) == NULL)
      failed ("i2t: failed n1");     
  if ((p[0] = (int *) malloc ((size_t) n1 * n2 * sizeof (int))) == NULL)
      failed ("i2t: failed n2");
  for (i = 0; i < n1 - 1; i++)
    p[i + 1] = p[i] + n2;
  for (i = 0, a = p[0]; i < n1 * n2; i++)
    *a++ = 0;
  return p;
}

int ***i3t (int n1, int n2, int n3)
{
  int ***p, *a;
  int i, j;
  if ((p = (int ***) malloc ((size_t) n1 * sizeof (int **))) == NULL)
      failed ("i3t: failed n1");
  if ((p[0] = (int **) malloc ((size_t) n1 * n2 * sizeof (int *))) == NULL)
      failed ("i3t: failed n2");
  if ((p[0][0] = (int *) malloc ((size_t) n1 * n2 * n3 * sizeof (int))) == NULL)
      failed ("i3t: failed n3");
  for (i = 0; i < n2 - 1; i++)
    p[0][i + 1] = p[0][i] + n3;
  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      for (j = 0; j < n2 - 1; j++)
	p[i + 1][j + 1] = p[i + 1][j] + n3;
    }
  for (i = 0, a = p[0][0]; i < n1 * n2 * n3; i++)
    *a++ = 0;
  return p;
}

int ****i4t (int n1, int n2, int n3, int n4)
{
  int ****p, *a;
  int i, j, k;
  if ((p = (int ****) malloc ((size_t) n1 * sizeof (int ***))) == NULL)
      failed ("i4t: failed n1");
  if ((p[0] = (int ***) malloc ((size_t) n1 * n2 * sizeof (int **))) == NULL)
      failed ("i4t: failed n2");
  if ((p[0][0] = (int **) malloc ((size_t) n1 * n2 * n3 * sizeof (int *))) == NULL)
      failed ("i4t: failed n3");
  if ((p[0][0][0] = (int *) malloc ((size_t) n1 * n2 * n3 * n4 * sizeof (int ))) == NULL)
      failed ("i4t: failed n4");

  for (i = 0; i < n3 - 1; i++)
    p[0][0][i + 1] = p[0][0][i] + n4;

  for (i = 0; i < n2 - 1; i++)
    {
      p[0][i + 1] = p[0][i] + n3;
      p[0][i + 1][0] = p[0][i][0] + n3 * n4;
      for (j = 0; j < n3 - 1; j++)
	p[0][i + 1][j + 1] = p[0][i + 1][j] + n4;
    }

  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      p[i + 1][0][0] = p[i][0][0] + n2 * n3 * n4;

      for (j = 0; j < n3 - 1; j++)
	p[i + 1][0][j + 1] = p[i + 1][0][j] + n4;

      for (j = 0; j < n2 - 1; j++)
	{
	  p[i + 1][j + 1] = p[i + 1][j] + n3;
	  p[i + 1][j + 1][0] = p[i + 1][j][0] + n3 * n4;
	  for (k = 0; k < n3 - 1; k++)
	    p[i + 1][j + 1][k + 1] = p[i + 1][j + 1][k] + n4;
	}
    }

  for (i = 0, a = p[0][0][0]; i < n1 * n2 * n3 * n4; i++)
    *a++ = 0.0;

  return p;
}


float *f1t (int n1)
{
  float *p, *a;
  int i;
  if ((p = (float *) malloc ((size_t) n1 * sizeof (float))) == NULL)
      failed ("f1t: failed");
  for (i = 0, a = p; i < n1; i++)
    *a++ = 0;
  return p;
}

float **f2t (int n1, int n2)
{
  float **p, *a;
  int i;
  if ((p = (float **) malloc ((size_t) n1 * sizeof (float *))) == NULL)
      failed ("f2t: failed n1");
  if ((p[0] = (float *) malloc ((size_t) n1 * n2 * sizeof (float))) == NULL)
      failed ("f2t: failed n2");
  for (i = 0; i < n1 - 1; i++)
    p[i + 1] = p[i] + n2;
  for (i = 0, a = p[0]; i < n1 * n2; i++)
    *a++ = 0;
  return p;
}

float ***f3t (int n1, int n2, int n3)
{
  float ***p, *a;
  int i, j;
  if ((p = (float ***) malloc ((size_t) n1 * sizeof (float **))) == NULL)
      failed ("f3t: failed n1");
  if ((p[0] = (float **) malloc ((size_t) n1 * n2 * sizeof (float *))) == NULL)
      failed ("f3t: failed n2");
  if ((p[0][0] = (float *) malloc ((size_t) n1 * n2 * n3 * sizeof (float))) == NULL)
      failed ("f3t: failed n3");
  for (i = 0; i < n2 - 1; i++)
    p[0][i + 1] = p[0][i] + n3;
  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      for (j = 0; j < n2 - 1; j++)
	p[i + 1][j + 1] = p[i + 1][j] + n3;
    }
  for (i = 0, a = p[0][0]; i < n1 * n2 * n3; i++)
    *a++ = 0;
  return p;
}

float ****f4t (int n1, int n2, int n3, int n4)
{
  float ****p, *a;
  int i, j, k;
  if ((p = (float ****) malloc ((size_t) n1 * sizeof (float ***))) == NULL)
      failed ("f4t: failed n1");
  if ((p[0] = (float ***) malloc ((size_t) n1 * n2 * sizeof (float **))) == NULL)
      failed ("f4t: failed n2");
  if ((p[0][0] = (float **) malloc ((size_t) n1 * n2 * n3 * sizeof (float *))) == NULL)
      failed ("f4t: failed n3");
  if ((p[0][0][0] = (float *) malloc ((size_t) n1 * n2 * n3 * n4 * sizeof (float))) == NULL)
      failed ("f4t: failed n4");

  for (i = 0; i < n3 - 1; i++)
    p[0][0][i + 1] = p[0][0][i] + n4;

  for (i = 0; i < n2 - 1; i++)
    {
      p[0][i + 1] = p[0][i] + n3;
      p[0][i + 1][0] = p[0][i][0] + n3 * n4;
      for (j = 0; j < n3 - 1; j++)
	p[0][i + 1][j + 1] = p[0][i + 1][j] + n4;
    }

  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      p[i + 1][0][0] = p[i][0][0] + n2 * n3 * n4;

      for (j = 0; j < n3 - 1; j++)
	p[i + 1][0][j + 1] = p[i + 1][0][j] + n4;

      for (j = 0; j < n2 - 1; j++)
	{
	  p[i + 1][j + 1] = p[i + 1][j] + n3;
	  p[i + 1][j + 1][0] = p[i + 1][j][0] + n3 * n4;
	  for (k = 0; k < n3 - 1; k++)
	    p[i + 1][j + 1][k + 1] = p[i + 1][j + 1][k] + n4;
	}
    }

  for (i = 0, a = p[0][0][0]; i < n1 * n2 * n3 * n4; i++)
    *a++ = 0.0;

  return p;
}

float *****f5t (int n1, int n2, int n3, int n4, int n5)
{
  float *****p, *a;
  int i, j, k, l;
  if ((p = (float *****) malloc ((size_t) n1 * sizeof (float ****))) == NULL)
      failed ("f5t: failed n1");
  if ((p[0] = (float ****) malloc ((size_t) n1 * n2 * sizeof (float ***))) == NULL)
      failed ("f5t: failed n2");
  if ((p[0][0] =
    (float ***) malloc ((size_t) n1 * n2 * n3 * sizeof (float **))) == NULL)
      failed ("f5t: failed n3");
  if ((p[0][0][0] =
  (float **) malloc ((size_t) n1 * n2 * n3 * n4 * sizeof (float *))) == NULL)
      failed ("f5t: failed n4");
  if ((p[0][0][0][0] =
       (float *) malloc ((size_t) n1 * n2 * n3 * n4 * n5 * sizeof (float))) == NULL)
      failed ("f5t: failed n5");

  for (i = 0; i < n4 - 1; i++)
    p[0][0][0][i + 1] = p[0][0][0][i] + n5;

  for (i = 0; i < n3 - 1; i++)
    {
      p[0][0][i + 1] = p[0][0][i] + n4;
      p[0][0][i + 1][0] = p[0][0][i][0] + n4 * n5;
      for (j = 0; j < n4 - 1; j++)
	p[0][0][i + 1][j + 1] = p[0][0][i + 1][j] + n5;
    }

  for (i = 0; i < n2 - 1; i++)
    {
      p[0][i + 1] = p[0][i] + n3;
      p[0][i + 1][0] = p[0][i][0] + n3 * n4;
      p[0][i + 1][0][0] = p[0][i][0][0] + n3 * n4 * n5;

      for (j = 0; j < n4 - 1; j++)
	p[0][i + 1][0][j + 1] = p[0][i + 1][0][j] + n5;

      for (j = 0; j < n3 - 1; j++)
	{
	  p[0][i + 1][j + 1] = p[0][i + 1][j] + n4;
	  p[0][i + 1][j + 1][0] = p[0][i + 1][j][0] + n4 * n5;
	  for (k = 0; k < n4 - 1; k++)
	    p[0][i + 1][j + 1][k + 1] = p[0][i + 1][j + 1][k] + n5;
	}
    }

  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      p[i + 1][0][0] = p[i][0][0] + n2 * n3 * n4;
      p[i + 1][0][0][0] = p[i][0][0][0] + n2 * n3 * n4 * n5;

      for (j = 0; j < n4 - 1; j++)
	p[i + 1][0][0][j + 1] = p[i + 1][0][0][j] + n5;

      for (j = 0; j < n3 - 1; j++)
	{
	  p[i + 1][0][j + 1] = p[i + 1][0][j] + n4;
	  p[i + 1][0][j + 1][0] = p[i + 1][0][j][0] + n4 * n5;
	  for (k = 0; k < n4 - 1; k++)
	    p[i + 1][0][j + 1][k + 1] = p[i + 1][0][j + 1][k] + n5;
	}

      for (j = 0; j < n2 - 1; j++)
	{
	  p[i + 1][j + 1] = p[i + 1][j] + n3;
	  p[i + 1][j + 1][0] = p[i + 1][j][0] + n3 * n4;
	  p[i + 1][j + 1][0][0] = p[i + 1][j][0][0] + n3 * n4 * n5;

	  for (k = 0; k < n3 - 1; k++)
	    p[i + 1][j + 1][0][k + 1] = p[i + 1][j + 1][0][k] + n5;

	  for (k = 0; k < n3 - 1; k++)
	    {
	      p[i + 1][j + 1][k + 1] = p[i + 1][j + 1][k] + n4;
	      p[i + 1][j + 1][k + 1][0] = p[i + 1][j + 1][k][0] + n4 * n5;
	      for (l = 0; l < n4 - 1; l++)
		p[i + 1][j + 1][k + 1][l + 1] = p[i + 1][j + 1][k + 1][l] + n5;
	    }
	}
    }

  for (i = 0, a = p[0][0][0][0]; i < n1 * n2 * n3 * n4 * n5; i++)
    *a++ = 0.0;

  return p;
}

double *d1t (int n1)
{
  double *p, *a;
  int i;
  if ((p = (double *) malloc ((size_t) n1 * sizeof (double))) == NULL)
      failed ("d1t: failed");
  for (i = 0, a = p; i < n1; i++)
    *a++ = 0;
  return p;
}

double **d2t (int n1, int n2)
{
  double **p, *a;
  int i;
  if ((p = (double **) malloc ((size_t) n1 * sizeof (double *))) == NULL)
      failed ("d2t: failed n1");
  if ((p[0] = (double *) malloc ((size_t) n1 * n2 * sizeof (double))) == NULL)
      failed ("d2t: failed n2");
  for (i = 0; i < n1 - 1; i++)
    p[i + 1] = p[i] + n2;
  for (i = 0, a = p[0]; i < n1 * n2; i++)
    *a++ = 0;
  return p;
}

double ***d3t (int n1, int n2, int n3)
{
  double ***p, *a;
  int i, j;
  if ((p = (double ***) malloc ((size_t) n1 * sizeof (double **))) == NULL)
      failed ("d3t: failed n1");
  if ((p[0] = (double **) malloc ((size_t) n1 * n2 * sizeof (double *))) == NULL)
      failed ("d3t: failed n2");
  if ((p[0][0] = (double *) malloc ((size_t) n1 * n2 * n3 * sizeof (double))) == NULL)
      failed ("d3t: failed n3");
  for (i = 0; i < n2 - 1; i++)
    p[0][i + 1] = p[0][i] + n3;
  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      for (j = 0; j < n2 - 1; j++)
	p[i + 1][j + 1] = p[i + 1][j] + n3;
    }
  for (i = 0, a = p[0][0]; i < n1 * n2 * n3; i++)
    *a++ = 0;
  return p;
}



double ****d4t (int n1, int n2, int n3, int n4)
{
  double ****p, *a;
  int i, j, k;
  if ((p = (double ****) malloc ((size_t) n1 * sizeof (double ***))) == NULL)
      failed ("d4t: failed n1");
  if ((p[0] = (double ***) malloc ((size_t) n1 * n2 * sizeof (double **))) == NULL)
      failed ("d4t: failed n2");
  if ((p[0][0] = (double **) malloc ((size_t) n1 * n2 * n3 * sizeof (double *))) == NULL)
      failed ("d4t: failed n3");
  if ((p[0][0][0] = (double *) malloc ((size_t) n1 * n2 * n3 * n4 * sizeof (double ))) == NULL)
      failed ("d4t: failed n4");

  for (i = 0; i < n3 - 1; i++)
    p[0][0][i + 1] = p[0][0][i] + n4;

  for (i = 0; i < n2 - 1; i++)
    {
      p[0][i + 1] = p[0][i] + n3;
      p[0][i + 1][0] = p[0][i][0] + n3 * n4;
      for (j = 0; j < n3 - 1; j++)
	p[0][i + 1][j + 1] = p[0][i + 1][j] + n4;
    }

  for (i = 0; i < n1 - 1; i++)
    {
      p[i + 1] = p[i] + n2;
      p[i + 1][0] = p[i][0] + n2 * n3;
      p[i + 1][0][0] = p[i][0][0] + n2 * n3 * n4;

      for (j = 0; j < n3 - 1; j++)
	p[i + 1][0][j + 1] = p[i + 1][0][j] + n4;

      for (j = 0; j < n2 - 1; j++)
	{
	  p[i + 1][j + 1] = p[i + 1][j] + n3;
	  p[i + 1][j + 1][0] = p[i + 1][j][0] + n3 * n4;
	  for (k = 0; k < n3 - 1; k++)
	    p[i + 1][j + 1][k + 1] = p[i + 1][j + 1][k] + n4;
	}
    }

  for (i = 0, a = p[0][0][0]; i < n1 * n2 * n3 * n4; i++)
    *a++ = 0.0;

  return p;
}


void 
readeol (FILE * fp)
{
  char s;
  while ((s = getc (fp)) != EOF)
    if (s == '\n')
      return;
}


int myipow (int a, int n)
{
  int b = a;
  while (--n > 0)
    a *= b;
  return a;
}

float 
myfpow (float a, int n)
{
  float b = a;
  while (--n > 0)
    a *= b;
  return a;
}

double mydpow (double a, int n)
{
  double b = a;
  while (--n > 0)
    a *= b;
  return a;
}

void pdarray (int n, int m, double **a)
{
  int i, j;
  printf ("\n");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	printf ("%8.4f ", a[i][j]);
      printf ("\n");
    }
}

void pdvector (int n, double *a)
{
  int i;
  printf ("\n");
  for (i = 0; i < n; i++)
    printf ("%8.4f ", a[i]);
  printf ("\n");
}

void pfarray (int n, int m, float **a)
{
  int i, j;
  printf ("\n");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	printf ("%8.4f ", a[i][j]);
      printf ("\n");
    }
}

void pfvector (int n, float *a)
{
  int i;
  printf ("\n");
  for (i = 0; i < n; i++)
    printf ("%8.4f ", a[i]);
  printf ("\n");
}

void piarray (int n, int m, int **a)
{
  int i, j;
  printf ("\n");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	printf ("%8d ", a[i][j]);
      printf ("\n");
    }
}

void pivector (int n, int *a)
{
  int i;
  printf ("\n");
  for (i = 0; i < n; i++)
    printf ("%8d ", a[i]);
  printf ("\n");
}

void zdarray (int n, int m, double **a)
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      a[i][j] = 0.0;
}

void zdvector (int n, double *a)
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = 0.0;
}

void zfarray (int n, int m, float **a)
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      a[i][j] = 0.0;
}

void zfvector (int n, float *a)
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = 0.0;
}

void ziarray (int n, int m, int **a)
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      a[i][j] = 0;
}

void zivector (int n, int *a)
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = 0;
}



/*********************************/

void free_c4t(char ****p){

  free(p[0][0][0]);
  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_c3t(char ***p){

  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_c2t(char **p){

  free(p[0]);
  free(p);
}

void free_c1t(char *p){

  free(p);
}


/*********************************/

void free_s4t(short ****p){

  free(p[0][0][0]);
  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_s3t(short ***p){

  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_s2t(short **p){

  free(p[0]);
  free(p);
}

void free_s1t(short *p){

  free(p);
}
/*********************************/

void free_i4t(int ****p){

  free(p[0][0][0]);
  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_i3t(int ***p){

  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_i2t(int **p){

  free(p[0]);
  free(p);
}

void free_i1t(int *p){

  free(p);
}

/*********************************/

void free_f5t(float *****p){

  free(p[0][0][0][0]);
  free(p[0][0][0]);
  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_f4t(float ****p){

  free(p[0][0][0]);
  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_f3t(float ***p){

  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_f2t(float **p){

  free(p[0]);
  free(p);
}

void free_f1t(float *p){

  free(p);
}

/*********************************/

void free_d4t(double ****p){

  free(p[0][0][0]);
  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_d3t(double ***p){

  free(p[0][0]);
  free(p[0]);
  free(p);
}

void free_d2t(double **p){

  free(p[0]);
  free(p);
}

void free_d1t(double *p){

  free(p);
}

/*********************************/

/* Chiama libreria messages.lib
void failed(char msg[]){

     fprintf(stderr,"%s",msg);
     exit(1);

}
*/

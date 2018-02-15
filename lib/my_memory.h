#ifndef HDR_MY_MEM
#define HDR_MY_MEM

#include "messages.h"
#include <stdio.h>

void readeol(FILE *fp);

int myipow(int a, int n);
float myfpow(float a, int n);
double mydpow(double a, int n);


FILE **F2t(int n1);
FILE ***F3t(int n1, int n2);

char *c1t(int n1);
char **c2t(int n1, int n2);
char ***c3t(int n1, int n2, int n3);
char ****c4t(int n1, int n2, int n3, int n4);
void free_c4t(char ****p);
void free_c3t(char ***p);
void free_c2t(char **p);
void free_c1t(char *p);

short *s1t(int n1);
short **s2t(int n1, int n2);
short ***s3t(int n1, int n2, int n3);
short ****s4t (int n1, int n2, int n3, int n4);
void free_s4t(short ****p);
void free_s3t(short ***p);
void free_s2t(short **p);
void free_s1t(short *p);

int *i1t(int n1);
int **i2t(int n1, int n2);
int ***i3t(int n1, int n2, int n3);
int ****i4t (int n1, int n2, int n3, int n4);
void free_i4t(int ****p);
void free_i3t(int ***p);
void free_i2t(int **p);
void free_i1t(int *p);


float *f1t(int n1);
float **f2t(int n1, int n2);
float ***f3t(int n1, int n2, int n3);
float ****f4t(int n1, int n2, int n3, int n4);
float *****f5t(int n1, int n2, int n3, int n4, int n5);
void free_f5t(float *****p);
void free_f4t(float ****p);
void free_f3t(float ***p);
void free_f2t(float **p);
void free_f1t(float *p);

double *d1t(int n1);
double **d2t(int n1, int n2);
double ***d3t(int n1, int n2, int n3);
double ****d4t(int n1, int n2, int n3, int n4);
void free_d4t(double ****p);
void free_d3t(double ***p);
void free_d2t(double **p);
void free_d1t(double *p);


void pdarray(int n, int m, double **a);
void pdvector(int n, double *a);
void pfarray(int n, int m, float **a);
void pfvector(int n, float *a);
void piarray(int n, int m, int **a);
void pivector(int n, int *a);

void zdarray(int n, int m, double **a);
void zdvector(int n, double *a);
void zfarray(int n, int m, float **a);
void zfvector(int n, float *a);
void ziarray(int n, int m, int **a);
void zivector(int n, int *a);
#endif

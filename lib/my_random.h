#ifndef HDR_MY_RND
#define HDR_MY_RND

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//long int idum = ( -1 );
void initialize_prng ( long int seed );

double myrandom(int *iseed);

float ran2    ( long *idum );
int   intran2 ( long *idum, int max);
float gasdev  ( long *idum );

#endif /*HDR_MY_RND*/

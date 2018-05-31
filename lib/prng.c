/* 
      Random number generator from paper by Marsaglia, G., Narasimhan, B., and
	Zaman, A. 
	Written by Buks van Rensburg and Daniel Gruner.
	April 25, 1990
*/

#include <stdio.h>
#include <math.h>
#include "prng.h"
//extern FILE *out_save;

/* macros 

   floating point numbers up to 6 decimal places, double precision to 14
   decimal places

*/

/* 2**32 */
#define MAXINT				0xffffffff
/* 2**32 - 5 */
#define MAXINT_LESS_5	0xfffffffa
/* 1 / 2**32 */
#define INVERSE_MAXINT	2.328306e-10
/* 1 / 2**31 */
#define INVERSE_MAXINT_2	4.656612e-10
/* 1 / 2**64 */
#define INVERSE_MAXDOUBLEINT	5.42101086495187e-20
/* 1 / 2**63 */
#define INVERSE_MAXDOUBLEINT_2	10.84202172990374e-20
/* "magic number" for Weyl generator (see above reference) */
#define KWEYL				362436069

/* global variables */

static unsigned int	iran[43];
static unsigned int	iran1, ic, kounter;
static unsigned int	MaxInt = MAXINT;
static unsigned int	MaxInt5 = MAXINT_LESS_5;


/*
	float ran1real_( )

	Function to generate random numbers in the interval [0,1)
	(single precision).
	raninit(n) must be called prior to using this routine, as it initializes
	the seeds and counters.
*/
float	ran1real_( )
{
	int	ir;
	float	r;

	ir = iran[(kounter + 43 - 22) % 43] - iran[kounter] - ic;
	if( ir < 0 )
	{
		iran[kounter] = (ir + MaxInt5) % MaxInt5;
		ic = 1;
	}
	else
	{
		iran[kounter] = ir % MaxInt5;
		ic = 0;
	}
	iran1 -= KWEYL;
	r = (iran[kounter] - iran1) * INVERSE_MAXINT;
	kounter = (kounter + 1) % 43;
	return r;
}


/*
	 float ran2real_( void )

	 Function to generate random numbers in the interval [-1,1)
	 (single precision).
	 raninit(n) must be called prior to using this routine, as it initializes
	 the seeds and counters.
	 */
float	ran2real_( )
{
	int	ir;
	float	r;

	ir = iran[(kounter + 43 - 22) % 43] - iran[kounter] - ic;
	if( ir < 0 )
	{
		iran[kounter] = (ir + MaxInt5) % MaxInt5;
		ic = 1;
	}
	else
	{
		iran[kounter] = ir % MaxInt5;
		ic = 0;
	}
	iran1 -= KWEYL;
	r = (iran[kounter] - iran1) * INVERSE_MAXINT_2 - 1.0;
	kounter = (kounter + 1) % 43;
	return r;
}


/*
	double ran1double_( void )

	Function to generate random numbers in the interval [0,1)
	(double precision).
	raninit(n) must be called prior to using this routine, as it initializes
	the seeds and counters.
	In order to produce double precision random numbers, we generate to 
	random integers and add them, appropriately scaled and shifted, to produce
	a double precision real return value.
*/
double	ran1double_( )
{
	int		ir;
	double	r;

	/* generate first random integer */
	ir = iran[(kounter + 43 - 22) % 43] - iran[kounter] - ic;
	if( ir < 0 )
	{
		iran[kounter] = (ir + MaxInt5) % MaxInt5;
		ic = 1;
	}
	else
	{
		iran[kounter] = ir % MaxInt5;
		ic = 0;
	}
	iran1 -= KWEYL;
	/* first part of double precision value (scaled by 2**-32) gets stored in r */
	r = (double) (iran[kounter] - iran1) * INVERSE_MAXINT;
	kounter = (kounter + 1) % 43;
	/* generate second random integer */
	ir = iran[(kounter + 43 - 22) % 43] - iran[kounter] - ic;
	if( ir < 0 )
	{
		iran[kounter] = (ir + MaxInt5) % MaxInt5;
		ic = 1;
	}
	else
	{
		iran[kounter] = ir % MaxInt5;
		ic = 0;
	}
	iran1 -= KWEYL;
	/* add second part of double precision value, this time scaled by 2**-64 */
	r += (double) (iran[kounter] - iran1) * INVERSE_MAXDOUBLEINT;
	kounter = (kounter + 1) % 43;
	return r;
}


/*
	double ran2double_( void )

	Function to generate random numbers in the interval [-1,1)
	(double precision).
	raninit(n) must be called prior to using this routine, as it initializes
	the seeds and counters.
	In order to produce double precision random numbers, we generate to 
	random integers and add them, appropriately scaled and shifted, to produce
	a double precision real return value.
*/
double	ran2double_( )
{
	int		ir;
	double	r;

	/* generate first random integer */
	ir = iran[(kounter + 43 - 22) % 43] - iran[kounter] - ic;
	if( ir < 0 )
	{
		iran[kounter] = (ir + MaxInt5) % MaxInt5;
		ic = 1;
	}
	else
	{
		iran[kounter] = ir % MaxInt5;
		ic = 0;
	}
	iran1 -= KWEYL;
	/* first part of double precision value (scaled by 2**-32) gets stored in r */
	r = (double) (iran[kounter] - iran1) * INVERSE_MAXINT_2;
	kounter = (kounter + 1) % 43;
	/* generate second random integer */
	ir = iran[(kounter + 43 - 22) % 43] - iran[kounter] - ic;
	if( ir < 0 )
	{
		iran[kounter] = (ir + MaxInt5) % MaxInt5;
		ic = 1;
	}
	else
	{
		iran[kounter] = ir % MaxInt5;
		ic = 0;
	}
	iran1 -= KWEYL;
	/* add second part of double precision value, this time scaled by 2**-64 */
	r += (double) (iran[kounter] - iran1) * INVERSE_MAXDOUBLEINT_2;
	kounter = (kounter + 1) % 43;
	return r - (double) 1.0;
}



/*
	int	ranint_(int nmax)

	Returns a random integer between 0 and nmax - 1 (for nmax > 0)
	or between 0 and nmax + 1 (for nmax < 0).
	Uses ran1real_() to get uniform deviates in the unit interval [0,1).

*/
inline int	ranint_( int nmax)
{
	return (int) (ran1real_() * (float) nmax);
}



/*
	void	initran_(unsigned int *n)

	Initialize the random number generator.
	Takes one seed as input, and produces the initial 43 random numbers needed
	for the generator.

	The vector iran contains the last 43 random integers, while iran1 is a 
	random integer generated by a Weyl scheme.  ic is the subtraction and 
	kounter keeps track of the coordinate of the last integer generated.
*/
void	initran_(  unsigned int *n)
{
	int i, i1, j1;
	unsigned int	m, mm[3];
	unsigned int	bit;

	kounter = 0;
	ic = 0;
	m = *n;

	/* generate 3 other seeds by the Weyl method */
	iran1 = m;
	for( i = 0; i < 3; i++ )
	{
		mm[i] = iran1 - KWEYL;
		iran1 = mm[i];
	}

	/* generate the iran vector */
	for( i1 = 0; i1 < 43; i1++ )
	{
		iran[i1] = 0;
		for( j1 = 1; j1 <= 32; j1++ )
		{
			i = j1 + 32 * i1;
			bit = m * mm[i % 3];
			if( (bit % 64) < 32 )
				bit = 0;
			else
				bit = 1;
			iran[i1] += bit << (j1 - 1);
			mm[i % 3] = (mm[0] * mm[1] * mm[2]) % 179;
			m = (53 * m + 1) % 169;
		}
	}

	/* generate iran1 */
	iran1 = 0;
	for( i = 1; i <= 32; i++ )
	{
		bit = m * mm[i % 3];
		if( (bit % 64) < 32 )
			bit = 0;
		else
			bit = 1;
		iran1 += bit << (i - 1);
		mm[i % 3] = (mm[0] * mm[1] * mm[2]) % 179;
		m = (53 * m + 1) % 169;
	}
}

/*void	ran_read()
{
  int i;
  fscanf(out_save,"%d %d %d",&kounter,&iran1,&ic);
  for(i= 0; i<43; i++) {
  fscanf(out_save,"%d",&iran[i]);
  }
}

void	ran_write()
{
  int i;
  fprintf(out_save,"%d %d %d\n",kounter,iran1,ic);
  for(i= 0; i<43; i++) fprintf(out_save,"%d\n",iran[i]);
}
*/

#include <stdlib.h>
#include <stdio.h>
#include "messages.h"

void failed (char message[])
{
  fprintf (stderr,"Error. \n FAILED *** %s ***\n \n", message);
  abort ();
  //exit (1);
}
void checkpoint(char message[]){

printf ("\n CHECKPOINT *** %s ***\n \n", message);

}

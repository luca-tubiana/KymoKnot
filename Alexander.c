#include "Alexander.h"
#include "my_memory.h"
#include "my_geom.h"
#include "messages.h"
#include <math.h>
#include <stdlib.h>

ALX_wspace * ALX_wspace_alloc ( int N )
{
  ALX_wspace * ws;
  int dim = 4 * N; //in realta` andrebbe (N+1)^2/9 ma non ho memoria..
  ws = malloc(sizeof(ALX_wspace));
  if(ws == NULL)
  {
    failed("unable to allocate memory for Alexander determinants computation \n");
  }
  /*
   * alex_generict consider the ring to be composed of N+1 beads,
   * with beads 0 and N equal.
   * Space must be allocated accordingly.
   */
  ws->intersec     = i1t ( dim );
  ws->type         = i2t ( dim, dim );
  ws->sign         = i2t ( dim, dim );
  ws->cross        = i2t ( dim, dim );
  ws->alex_mat     = d2t ( dim ,  dim );
  ws->x_in         = d2t ( dim ,  dim );
  ws->matrix_dim   = dim ;
  ws->n_crossing   = dim ;

  return ws;
}

void ALX_free_wspace ( ALX_wspace * ws )
{
  if( NULL != ws )
  {
    free_i1t ( ws->intersec );
    free_i2t ( ws->type     );
    free_i2t ( ws->sign     );
    free_i2t ( ws->cross    );
    free_d2t ( ws->alex_mat  );
    free_d2t ( ws->x_in     );
    free     ( ws           );
  }
}

// routines da alphalex_generict_multit.c

double ALX_detalex(double **alex_mat, int nnn)  // banale utilizzo della decomp. LU. V. Num. Rec. in C
{
   int      i, imax, j, k;
   double   big, dum, sum, temp;
   double * vv;
   double   d;  // Il determinante

   vv  = d1t(nnn);
   d   = 1.0;

   for ( i = 0 ; i < nnn ; i++ )
   {
      big = 0.0;
      for ( j = 0 ; j < nnn ; j++ )
      {
         if (( temp = fabs ( alex_mat[i][j] ) ) > big )
         {
           big = temp;
         }
      }
      if ( 0.0 == big ) return 0.0; // Errore, det=0!!!
      vv[i] = 1.0 / big;
   }
   for ( j = 0 ; j < nnn ; j++ )
   {
      for ( i = 0 ; i < j ; i++ )
      {
         sum = alex_mat[i][j];
	 for ( k = 0 ; k < i ; k++ )
         {
           sum -= alex_mat[i][k] * alex_mat[k][j];
         }
	 alex_mat[i][j] = sum;
      }
      big = 0.0;
      for ( i = j ; i < nnn ; i++ )
      {
        sum = alex_mat[i][j];
        for ( k = 0 ; k < j ; k++ )
        {
          sum -= alex_mat[i][k] * alex_mat[k][j];
        }
        alex_mat[i][j] = sum;
        if ( ( dum = vv[i] * fabs(sum) ) >= big)
        {
          big  = dum;
	  imax = i;
        }
      }
      if (j != imax)
      {
        for ( k = 0 ; k < nnn ; k++ )
        {
          dum               = alex_mat[imax][k];
	  alex_mat[imax][k] = alex_mat[j][k];
	  alex_mat[j][k]    = dum;
	 }
	 d        = -d;
	 vv[imax] = vv[j];
      }
      if (alex_mat[j][j] == 0)
      {
        alex_mat[j][j]=1.0e-20;
      }
      if (j != ( nnn-1 ) )
      {
         dum = 1.0/(alex_mat[j][j]);
	 for ( i = j+1 ; i < nnn ; i++ )
         {
           alex_mat[i][j] *= dum;
         }
      }
   }
   free_d1t(vv);
   // for (i=0;i<nnn;i++){for (j=0;j<nnn;j++) printf("%f\n",alex[i][j]);}
   for ( j = 0 ; j < nnn ; j++ )
   {
     d = d * alex_mat[j][j];
   }
//   printf("  det=%f",d);
   return d;
}


double  ALX_alex_generict ( int N , double ** prj_chain , int numt, int t[numt], int out_det[numt] ,  ALX_wspace * wspace )
{
  // Le solite variabili di loop e di lavoro
  int i, j, jt, k;
  int b1, b2;
  int b , bb;
  int ok     = 1;
  int signus = 1;//, flag=FALSE;

  double a, aa;

  /* detcr=determinante di cramer x check intersez. fra rette
    - da non confondere con quello generico;
    xi, x1,y1,x2,y2,x1p,y1p,x2p,yp,z,zp sono variabili di lavoro
  dall'uso, credo, abbastanza intuitivo... */

  double detcr,
         xi,
         x1,  y1,
         x2,  y2,
         x1p, y1p,
         x2p, y2p,
         z  ,  zp;
  double v_1[3];
  double norm_1, norm_2;

  /* costant: costante usata per rendere il detcr un numero "ragionevole"
  (se ?troppo piccolo -> grandi errori e possibilita' di overflow.
   Non dovrebbe, in teoria, essere troppo grande
   (i vettori sono proiez. di vettori unitari -> norma <=1
  -> det=volume<=1 c.a. !!!   */

  //float costant=1.0;

  int  ninters[5000];

  /* ncr=numero di crossing totale (la m. di Alexander e' nxr*nxr!)
     ncr2 quello di crossing meno (var. di lavoro)
     arco_l = usato per costruzione m. di Alex. (?l'arco l del Vanderzande) */

  int ncr    =  0,
      ncr2   =  0,
      arco_l = -1; // c3=0;
  /* variabili di lavoro per assegnamento valori matrice */
  int intersec_i , intersec_j;



  /*
  for ( j = 0 ; j < 3 ; j++ )
  {
     prj_chain[N][j] = prj_chain[0][j];
  }
  */

  // Inizio routine vera_e_propria.


  // Riempimento di prj_chaincoi primi length monomeri

  ninters[0]=0;

  for ( i = 0 ; i < N ; i++ )
  {
    wspace->intersec[i]=0;
  }

  /* Inizio controllo intersezioni. Prima si verifica se le rette si intersecano e poi se
  si intersecano effettivamente i monomeri! In teoria il tipo di proiezione e'
  t.c. non dovrebbeneanche servire (o quasi) il check dell'interesezione delle
  rette: quasi tutte (statisticamente) si intersecano! Ma io lascio 'o check lo
  stesso. REMARK: Re-check di questa parte IMP!!!!!*/

  for ( i = 0 ; i <= N - 2 ; i++ )
  {
    x1      = prj_chain[ i ][0];
    y1      = prj_chain[ i ][1];
    x2      = prj_chain[i+1][0];
    y2      = prj_chain[i+1][1];
    v_1[0]  = prj_chain[i+1][0] - prj_chain[i][0];
    v_1[1]  = prj_chain[i+1][1] - prj_chain[i][1];
    v_1[2]  = prj_chain[i+1][2] - prj_chain[i][2];
    norm_1  = norm_d(v_1,3);
    for ( j = i + 2 ; j < N ; j++ )
    {
      x1p     = prj_chain[ j ][0];
      y1p     = prj_chain[ j ][1];
      x2p     = prj_chain[ (j+1)%N ][0];
      y2p     = prj_chain[ (j+1)%N ][1];
      v_1[0]  = prj_chain[ (j+1)%N ][0] - prj_chain[j][0];
      v_1[1]  = prj_chain[ (j+1)%N ][1] - prj_chain[j][1];
      v_1[2]  = prj_chain[ (j+1)%N ][2] - prj_chain[j][2];
      norm_2  = norm_d(v_1,3);
      detcr   = ( ( x2 - x1 ) / norm_1 ) * ( ( y2p - y1p ) / norm_2 ) + ( ( x2p - x1p ) / norm_2 ) * ( ( y1 - y2 ) / norm_1 );
       if ( fabs(detcr) > EPSIL2 )
       {
         xi  = ( ( x2  * y1  - x1 *  y2  ) / norm_1 ) * ( ( x2p - x1p ) / norm_2 );
         xi -= ( ( x2p * y1p - x1p * y2p ) / norm_2 ) * ( ( x2  - x1  ) / norm_1 );
         xi *= 1.0/detcr;

         intersec_i = wspace->intersec[i]; // le "chiamate" a elem. di matrici richiedono tempo.....
         wspace->x_in[i][intersec_i] = xi;

   /* Check intersez. effettiva. Funziona *solo* se nessuna delle due rette
         verticale, come dovrebbe essere praticamente sempre. VERIFICARE!!! */

         if ( ( xi > min( x1, x2 ) ) && ( xi < max( x1, x2 ) ) )
         {
           ok = 1;
         }
         else
         {
           ok = 0;
         }
         if ( ( ok == 1 ) && ( xi > min( x1p, x2p ) ) && ( xi < max( x1p, x2p ) ) )
         {
           ok = 1;
         }
         else
         {
           ok = 0;
         }

         if (ok)
         {
           intersec_j = wspace->intersec[j];
           wspace->x_in[j][intersec_j] = xi; // Naturalmente se a interseca b anche b interseca a

/*Adesso mi servono anche le z delle due rette nel p.to di intersez. x stabilire
 se il crossing ?"su" o "giu'" !!! Tecnica usata: la retta proiettata ?del tipo
     Pproj(q)=Aproj+qVproj, con Aproj,Bproj pti di partenza e arrivo, V vettore
(= B-A),e q parametro reale. Trovo q t.c. Pproj(q)=(xin,yin). Poi lo sost. nell'
espressione della retta di partenza in 3D (che ?of course P(q)=A+qV). Lo faccio
   per entrambi i monomeri naturalmente!! Basta usare una sola coordinata!!!
     q ?xin[][] (ecco il suo "doppio uso")             */

           wspace->x_in[i][intersec_i] = ( xi - x1  ) / ( x2  - x1  );
           wspace->x_in[j][intersec_j] = ( xi - x1p ) / ( x2p - x1p );
           z  = prj_chain[i][2] + wspace->x_in[i][intersec_i] *( prj_chain[ i+1 ][2] - prj_chain[i][2] );
           zp = prj_chain[j][2] + wspace->x_in[j][intersec_j] *( prj_chain[ (j+1)%N ][2] - prj_chain[j][2] );

        /*  Condenso l'info sul segno del crossing E l'altro bond coinvolto
    in un unico elem. di matrice (ok, non mi daranno il nobel per questo...) */

           if (z>zp)
           {
             ok = 1;
           }
           else
           {
             ok = -1;  // Doppio uso di ok. E vabbuo'
           }

           wspace->sign[i][intersec_i] =  ok * ( j + 1 ) * signus;
           wspace->sign[j][intersec_j] = -ok * ( i + 1 ) * signus;

           ncr++;  // Update #1...
            /*====================================================*/
            /*	       if (ncr==1&&flag==FALSE)
             *	       {
             *	       flag=TRUE;
             *	       if (wspace->sign[i][0]>0)
             *	       signus=-1;//signus=-theta_di_heaviside(wspace->sign[i][0]);
             *	       wspace->sign[i][intersez[i]]*=signus;
             *	       wspace->sign[j][intersez[j]]*=signus;
             *	       }
             *	       */
            /*====================================================*/
           if ( ( ( y2p - y1p ) * ( x2 - x1 ) - ( x2p - x1p ) * ( y2 - y1 ) ) * ok > 0)
           {
             wspace->type[i][intersec_i]=wspace->type[j][intersec_j]=+1*signus;
           }
           else
           {
             wspace->type[i][intersec_i]=wspace->type[j][intersec_j]=-1*signus;
           }

	   wspace->intersec[j]++;
           wspace->intersec[i]++; // Update #2 ...
         }
       }
    }
    // for(k=0;k<intersec[i];k++) fprintf(stderr,"\n segno tipo  %d %d = %d  %d",i,k,wspace->sign[i][k],wspace->type[i][k]);//AUX
  }
   //   fprintf(stderr,"\nIn alexander_generict : Uscito dal grande ciclo ncr = %d N= %d",ncr,N);

  if (ncr<3)
  { // inutile perder tempo.....
    //modificato da LT 27-02-2010
    //ora resetta anche la variabile ritorno.
    for ( jt = 0 ; jt < numt ; jt++ )
    {
      out_det[jt] = 1;
    }

    return 1.0;
  }

  for ( i = 0 ; i < N ; i++ )
  {
    if ( i > 0 )
    {
       if (i == 1)
       {
         ninters[i] = wspace->intersec[0];
       }
       else
       {
         ninters[i] = wspace->intersec[ i-1 ] + ninters[ i-1 ];
       }
    }

    if ( wspace->intersec[i]  > 1 )
    {
      for (j = 1 ; j <= wspace->intersec[i] - 1 ; j++ )
      {
        a  = wspace->x_in[i][j];
        b1 = wspace->sign[i][j];
        b2 = wspace->type[i][j];
        k  = j - 1;
        while ( ( k > -1 ) && wspace->x_in[i][k] > a )
        {
          wspace->x_in[i][ k+1 ] = wspace->x_in[i][k];
          wspace->sign[i][ k+1 ] = wspace->sign[i][k];
          wspace->type[i][ k+1 ] = wspace->type[i][k];
          k--;
        }
        wspace->x_in[i][k+1] = a;
        wspace->sign[i][k+1] = b1;
        wspace->type[i][k+1] = b2;
      }
    }
  }
   /* Devo localizzare gli inizi dei ponti, che poi sono anche gli undercrossing,
   ed il ponte che attraversa ogni crossing.
   Purtroppo non potevo farlo prima (sob) perch?i crossing non erano ordinati!

   Analisi: seguo il polimero. OGNI volta che incontro un crossing "-", "me lo segno",
   e incremento il bridge number. Se incontro un crossing "+" */


//   printf("\n signus %d",signus);//AUX


  //fprintf(stderr,"ncr -> %d\n",ncr);

  for ( i = 0 ; i < N ; i++ )
  {
     for ( j = 0 ; j < wspace->intersec[i] ; j++)
     {
        if ( wspace->sign[i][j] < 0 )
        {
           wspace-> cross[i][j] = ncr2;
           ncr2++;
        }
     }
  }

  for ( jt = 0 ; jt < numt ; jt++ )
  {
    b2 = 0;
    for ( i = 0 ; i < N ; i++ )
    {
      for ( j = 0 ; j < wspace->intersec[i] ;j++)
      {
        if (wspace->sign[i][j]<0)
        {
          b2++;
        }
        else
        {
          b1 = 0;
          k  = wspace->sign[i][j] - 1;
          while (wspace->sign[k][b1]!=-(i+1))
          {
            b1++; // Ricerca posizione undercross...
          }
          k       = wspace->cross[k][b1];
          arco_l  = b2;
          if (arco_l>ncr-1)
          {
            arco_l = 0;
          }
          for ( ok = 0 ; ok < ncr ; ok++ )
          {
            wspace->alex_mat[k][ok] = 0;
          }
          if ( (k == arco_l) || (k+1 == arco_l ) )   // check, forse dovrebbe essere k+1=arco_l???
          {
            wspace->alex_mat[k][ k ]   = -1;
            wspace->alex_mat[k][ k+1 ] =  1;
          }
          else
          {
            if (wspace->type[i][j]==+1)  //tipo 2 secondo Vologodskii et al SovietPhysJETP 39, 6, 1060 ('74)
            {
              wspace->alex_mat[k][ k    ] = -t[jt];
              wspace->alex_mat[k][arco_l] =  t[jt] - 1;
              wspace->alex_mat[k][ k+1  ] =  1;
            }
            else
            {
              wspace->alex_mat[k][ k      ] =  1;
              wspace->alex_mat[k][ arco_l ] =  t[jt] - 1;
              wspace->alex_mat[k][ k+1    ] = -t[jt];
            }
          }
        }
      }
    }
    aa = ALX_detalex(wspace->alex_mat, ncr - 1 );

    while (fabs(aa)>1048000.)
    {
      aa = aa / 1024.;
    }
    if ( aa >= 0 )
    {
      bb = ( int ) ( aa + 0.49 );
    }
    else
    {
      bb = ( int ) ( aa - .49 );
    }

    /*ho sostituito l'if sul double con qualcosa di piu` sensato. LT*/
    /*if((int)(fabs(t[jt]))!=1){
      if (t[jt]<0.) {b=(int)(t[jt]-.01);}
      else {b=(int)(t[jt]+.01);}
      if(abs(bb)!=abs(b)){
       while (bb%b==0) {bb=bb/b;}
      }
    }*/
    if ( t[jt] != -1. )
    {
      if (t[jt]<0.)
      {
        b = ( int ) ( t[jt] - .01 );
      }
      else
      {
        b = ( int ) ( t[jt] + .01 );
      }
      while ( bb % b == 0 )
      {
        bb = bb / b;
      }
    }
    out_det[jt] =  ( abs ( bb ) );
  }
  return fabs( ( double ) bb );
}


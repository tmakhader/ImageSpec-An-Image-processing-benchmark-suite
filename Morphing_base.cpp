/*
No Optimisations Applied.
*/
#define ROWS 256  //number of rows
#define COLS 256  //number of columns
#define N 183
#include "stdint.h"
void morph_fade (int Start[ROWS][COLS], int End[ROWS][COLS], int Out[ROWS][COLS])

{
	int i=0,j,k=0;
    for (i =0; i<ROWS;i++)
     {
      for(j=0; j<COLS; j++)
      {
	   Out[i][j] = Start[i][j];
      }
    }
   for(k = 0; k < N; k++)
	 {
	  for(i = 0; i < ROWS; i++)
	    {
	    for(j=0;j < COLS;j++)
	     {
	       if(Out[i][j] < End[i][j])					
	         Out[i][j]++;
	       else if(Out[i][j] > End[i][j])
	         Out[i][j]--;							
	     }
	    }
     }
}

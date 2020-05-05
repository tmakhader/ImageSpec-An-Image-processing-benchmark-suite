#define ROWS 256  //number of rows
#define COLS 256  //number of columns
#define N 183
#include "stdint.h"
void morph_fade (int8_t Start[ROWS][COLS], int8_t End[ROWS][COLS],int8_t Out[ROWS][COLS])
{
#pragma HLS array_partition variable=Out block factor=20 dim=2
#pragma HLS array_partition variable=End block factor=20 dim=2
#pragma HLS array_partition variable=Start block factor=20 dim=2
	int16_t i=0,j,k=0;
    for (i =0; i<ROWS;i++)
     {
      for(j=0; j<COLS; j++)
      {
#pragma HLS unroll
	   Out[i][j] = Start[i][j];
      }
    }
   for(k = 0; k < N; k++)
	 {
	  for(i = 0; i < ROWS; i++)
	    {
#pragma HLS pipeline II=10
	    for(j=0;j < COLS;j++)
	     {
	       if(Out[i][j] > End[i][j])
	    	continue;
	       if(Out[i][j] < End[i][j])					//if current pixel value is less than target, increase current pixel value
	         Out[i][j]++;
	       else
	         Out[i][j]--;							//if current pixel value is more than target, decrease current pixel value
	     }
	    }
     }
}

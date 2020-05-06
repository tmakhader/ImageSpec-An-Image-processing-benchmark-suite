#include "stdint.h"
#define N 7
#define ROWS 256
int8_t sum_right,sum_left;
int full_window(int y, int x, int8_t input[ROWS][ROWS])
{
 int8_t sum=0;
 for(int j=-N/2;j<=N/2;j++)
 {
  for(int i=-N/2;i<=N/2;i++)
  {
   sum+=input[y+j][x+i];
  }
 }
 return(sum);
}
void window_pane(int y, int x, int8_t input[ROWS][ROWS])
{
 int i_left=x-N/2;
 int i_right=x+N/2+1;
 if(x!=ROWS-N/2-1)
 {
  for(int j=-N/2;j<=N/2;j++)
  {
   sum_left+=input[y+j][x+i_left];
   sum_right+=input[y+j][x+i_right];
  }
 }
}
void AMfilter(int8_t input[ROWS][ROWS], int8_t output[ROWS][ROWS])
{
 int x,y,i,j;
 int8_t sum;
 for(y=N/2;y<ROWS-N/2;y++)
 {
  sum=full_window(y,N/2,input);
  for(x=N/2;x<ROWS-N/2;x++)
  {
#pragma HLS pipeline II=7
   output[y][x]=sum/N*N;
   window_pane(y,x,input);
   sum=sum+=(sum_right-sum_left);
  }	
 }
}

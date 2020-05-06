#define N 7
#define ROWS 256
void AMfilter(int input[ROWS][ROWS], int output[ROWS][ROWS])
{
 int x,y,i,j,sum;
 for(y=N/2;y<ROWS-N/2;y++)
 {
  for(x=N/2;x<ROWS-N/2;x++)
  {
   sum=0;
   for(j=-N/2;j<=N/2;j++)
   {
   	for(i=-N/2;i<=N/2;i++)
   	{
     sum+=input[y+j][x+i];
   	}
   }
   output[y][x]=sum/N*N;
  }	
 }
}

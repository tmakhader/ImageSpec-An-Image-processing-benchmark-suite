#define ROWS 256
#include <math.h>
#define n 5
void YpMean(int input[ROWS][ROWS], int output[ROWS][ROWS], int p)
{
 int x,y,i,j,z,ar[121],a;
 float sum;
 for(y=n/2;y<ROWS-n/2;y++)
 {
  for(x=n/2;x<ROWS-n/2;x++)
  {
   z=0;
   for(j=-n/2;j<=n/2;j++)
   {
    for(i=-n/2;i<=n/2;i++)
    {
     ar[z]=input[y+j][x+i];
     z++;
    }
   } 
    z=0;
    sum=0.0;
    for(j=0;j<n*(n-1);j++)
    {
     if(ar[j]==0 && p<0)
      z=1;
     else
     sum+=pow(ar[j],p);
    } 
    if(z==1)
    {
     output[y][x]=0;	
    }
    else
    {
      if(sum==0.0)
      {
       a=0.0;	
      }	
      else
      {
       a=(int)pow((sum/n*n),(1.0)/p);
      }
      if(a>255)
      	a=255;
      output[y][x]=a;
    }	
  }	
 }	
}

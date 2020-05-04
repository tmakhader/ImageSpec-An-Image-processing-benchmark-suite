#include<math.h>
#define ROWS 64
void DCT(int input[ROWS][ROWS],int output[ROWS][ROWS])
{
 int X,Y,n,m;
 float sum,k0,k1,ktx,kty,pi,num,A;
 num=ROWS;
 k0=sqrt((double)(1)/(double)(num));
 k1=sqrt((double)(2)/(double)(num));
 for(m=0;m<num;m++)
 {
  for(n=0;n<num;n++)
  {
   sum=0.0;
   for(Y=0;Y<num;Y++)
   {
   	 A=cos((double)((2.0*(float)(Y+1))*(float)((m*pi)/(2.0*num))));	
   	for(X=0;X<num;X++)
   	{
   	  if(X==0)
   	   ktx=k0;
   	  else
   	   ktx=k1;
   	  if(Y==0)
   	   kty=k0;
   	  else
   	   kty=k1;
   	  sum+=input[Y][X]*cos((float)((2.0*(float)(n+1))*(float)((X*pi)/(2.0*num))))*A*ktx*kty;	    	
   	}
   }
   	if(n==0)
   	 sum*=k0;
   	else
   	 sum*=k1;
   	if(m==0)
   	 sum*=k0;
   	else
   	 sum*=k1;
   output[m][n]=sum;
  }	
 }	
}

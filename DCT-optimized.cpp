#include <math.h>
#include <stdint.h>
#define ROWS 64
#define num ROWS
#define k0 (float)sqrt((double)(1)/(double)(num))
#define k1 (float)sqrt((double)(2)/(double)(num))
#define pi (float)3.14
void DCT(int8_t input1[ROWS][ROWS/4],int8_t input2[ROWS][ROWS/4],int8_t input3[ROWS][ROWS/4],int8_t input4[ROWS][ROWS/4],float output[ROWS][ROWS],
		 float pre_comp[ROWS][ROWS],float pre_comp1[ROWS][ROWS/4],float pre_comp2[ROWS][ROWS/4],float pre_comp3[ROWS][ROWS/4],float pre_comp4[ROWS][ROWS/4])
{
 int X,Y,n,m;
 float sum,sum1,sum2,sum3,sum4,A;
 for(m=0;m<num;m++)
 {
  for(n=0;n<num;n++)
  {
  sum=(float)0.0;
   for(Y=0;Y<num;Y++)
   {
   sum1=(float)0.0;
   sum2=(float)0.0;
   sum3=(float)0.0;
   sum4=(float)0.0;
#pragma HLS pipeline II=8
   	 A=pre_comp[Y][m];
   	for(X=0;X<num/4;X++)
   	{
   	  sum1+=(float)input1[Y][X]*pre_comp1[n][X];
   	  sum2+=(float)input2[Y][X]*pre_comp2[n][X];
   	  sum3+=(float)input3[Y][X]*pre_comp3[n][X];
   	  sum4+=(float)input4[Y][X]*pre_comp4[n][X];
   	}
   	sum=sum+(sum1+sum2+sum3+sum4)*A;
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

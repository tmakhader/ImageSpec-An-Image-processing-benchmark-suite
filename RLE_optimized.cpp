#include <stdio.h>
#include<iostream>
#define ROWS 256
#define COLS 256
#include "stdint.h"
using namespace std;
int output[ROWS*COLS];
int p;
void encoder(int8_t input1[ROWS/4][COLS],int8_t input2[ROWS/4][COLS],int8_t input3[ROWS/4][COLS]
		     ,int8_t input4[ROWS/4][COLS],int16_t output1[ROWS/4*COLS],int16_t output2[ROWS/4*COLS]
		     ,int16_t output3[ROWS/4*COLS],int16_t output4[ROWS/4*COLS],int16_t S1,int16_t S2, int16_t S3, int16_t S4,int16_t E1,
			 int16_t E2,int16_t E3,int16_t E4)
{
 int16_t Count1=0,Count2=0,Count3=0,Count4=0,prev1,prev2,prev3,prev4;
 int16_t s1,s2,s3,s4,e1,e2,e3,e4;
 prev1=input1[0][0];
 prev2=input2[0][0];
 prev3=input3[0][0];
 prev4=input4[0][0];
 s1=0;
 s2=0;
 s3=0;
 s4=0;
 e1=0;
 e2=0;
 e3=0;
 e4=0;
 for(int i=0;i<ROWS/4;i++)
 {
  for(int j=0;j<COLS;j++)
  {
#pragma HLS pipeline
   if(input1[i][j]==prev1)
   {
   	Count1++;
   }
   else
   {
   	output1[e1++]=prev1;
   	output1[e1++]=Count1;
   	Count1=1;
   }
   if(input2[i][j]==prev2)
   {
   	Count2++;
   }
   else
   {
   	output2[e2++]=prev2;
   	output2[e2++]=Count2;
   	Count2=1;
   }
   if(input3[i][j]==prev3)
   {
   	Count3++;
   }
   else
   {
   	output3[e3++]=prev3;
   	output3[e3++]=Count3;
   	Count3=1;
   }
   if(input4[i][j]==prev4)
   {
   	Count4++;
   }
   else
   {
   	output4[e4++]=prev4;
   	output4[e4++]=Count4;
   	Count4=1;
   }
   prev1=input1[i][j];
   prev2=input2[i][j];
   prev3=input3[i][j];
   prev4=input4[i][j];
  }
 }

 output1[e1++]=prev1;
 output1[e1]=Count1;
 output2[e2++]=prev2;
 output2[e2]=Count2;
 output3[e3++]=prev3;
 output3[e3]=Count3;
 output4[e4++]=prev4;
 output4[e4]=Count4;
 if(output1[e1-1]==output2[s2])
 {
  output1[e1]+=output2[s2+1];
  s2+=2;
 }
 if(output2[e2-1]==output3[s3])
 {
  output2[e2]+=output3[s3+1];
  s3+=2;
 }
 if(output3[e3-1]==output4[s4])
 {
  output3[e3]+=output4[s4+1];
  s4+=2;
 }
 S1=s1;
 S2=s2;
 S3=s3;
 S4=s4;
 E1=e1;
 E2=e2;
 E3=e3;
 E4=e4;
}

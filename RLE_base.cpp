#include <stdio.h>
#include<iostream>
#define ROWS 3
#define COLS 3
using namespace std;
int output[ROWS*COLS];
int p;
void encoder(int input[ROWS][COLS])
{
 int Count=0,prev;
 prev=input[0][0];
 for(int i=0;i<ROWS;i++)
 {
  for(int j=0;j<COLS;j++)
  {
   if(input[i][j]==prev)
   {
   	Count++;
   }
   else
   {
   	output[p++]=prev;
   	output[p++]=Count;
   	Count=1;
   }
   prev=input[i][j];
  }
 }
 output[p++]=prev;
 output[p++]=Count;
}

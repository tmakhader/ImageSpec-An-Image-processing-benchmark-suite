// Simple line finding Hough Transform
//Inputs: int Img[][],int Acc[][], int threshold

#define ROWS 256
#define COLS 256
#include<stdio.h>
#include<math.h>
void hough(int Img[ROWS][COLS], long thresh, long &theta, long &rho)
{
	long Thresh;
	Thresh=thresh;
	long i,j,k,trho;
	int Acc[ROWS][COLS];
	for(i=0;i<ROWS;i++)
	{
	 for(j=0;j<COLS;j++)
	 {
	  Acc[i][j]=0;
	 }
	}
	// test each image pixel
	for(i=0;i<ROWS;i++)
	{
     for(j=0;j<COLS;j++)
     {
	  if(Img[i][j])
	   {
		 for(k=0;k<ROWS;k++)
		  {
			trho=(int)(i*cos(k)+ j*sin(k));
			++(Acc[k][trho]);
		  }
		}
	 }
	}

	// scan accumulator for max value
	
	for(i=0;i<ROWS;i++)
	{
	 for(j=0;j<COLS;j++)
	 {
	  if(Acc[i][j]>=Thresh)
	   {
		Thresh=Acc[i][j];
		rho=j;
		theta=i;
	   }
	 }
	}
 }
	

#include <stdio.h>
#include <math.h>
#define ROWS 256
#define COLS 256
#include <stdint.h>
void histogramEqualisation(int inp[ROWS][COLS],int out[ROWS][COLS]) {
	 int hist[256];
	int hist_equ[256];
	int i,j,curr=0,k;
	float multip=(255/(ROWS*COLS));
	// logic for calculating histogram
	for(i=0;i<256;i++)
	{
	 hist[i]=0;
	}
	for(i=0;i<ROWS;i++)
	{
	 for(j=0;j<COLS;j++)
	 {
	  ++hist[inp[i][j]];
	 }
	}

	// calculating cumulative frequency and new gray levels
	for (i = 0; i <256; i++)
	 {
	// cumulative frequency
		curr = curr + hist[i];
	// calculating new gray level
		hist_equ[i] = (int)(((float)curr)*multip);
	 }


	// performing histogram equalisation by mapping new gray levels
	for(i=0; i<ROWS; i++)
	{
     for(j=0; j<COLS; j++)
     {
	  out[i][j]=hist_equ[(inp[i][j])];
	 }
	}

}



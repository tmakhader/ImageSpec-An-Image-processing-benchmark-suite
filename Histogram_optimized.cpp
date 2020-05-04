#include <stdio.h>
#include <math.h>
#define ROWS 256
#define COLS 256
#include <stdint.h>
void histogramEqualisation(int8_t inp1[ROWS/4][COLS],int8_t inp2[ROWS/4][COLS],
		int8_t inp3[ROWS/4][COLS],int8_t inp4[ROWS/4][COLS],int8_t out1[ROWS/4][COLS],
		int8_t out2[ROWS/4][COLS],int8_t out3[ROWS/4][COLS],int8_t out4[ROWS/4][COLS])
{
	int8_t hist1[256],hist2[256],hist3[256],hist4[256];
	int8_t hist_equ1[256],hist_equ2[256],hist_equ3[256],hist_equ4[256];
	int i,j,curr=0,k,temp;
	float multip=(255/(ROWS*COLS));
	// logic for calculating histogram
	for(i=0;i<256;i++)
	{
#pragma HLS unroll
	 hist1[i]=0;
	 hist2[i]=0;
	 hist3[i]=0;
	 hist4[i]=0;
	}
	for(i=0;i<ROWS/4;i++)
	{
	 for(j=0;j<COLS;j++)
	 {
#pragma HLS pipeline
	  hist1[inp1[i][j]]+=1;
	  hist2[inp2[i][j]]+=1;
	  hist3[inp3[i][j]]+=1;
	  hist4[inp4[i][j]]+=1;
	 }
	}

	// calculating cumulative frequency and new gray levels
	for (i = 0; i <256; i++)
	 {
#pragma HLS pipeline
	// cumulative frequency
		curr = curr + hist1[i]+hist2[i]+hist3[i]+hist4[i];
	// calculating new gray level
		temp=(int)(((float)curr)*multip);
		hist_equ1[i] = temp;
		hist_equ2[i] = temp;
		hist_equ3[i] = temp;
		hist_equ4[i] = temp;
	 }


	// performing histogram equalisation by mapping new gray levels
	for(i=0; i<ROWS/4; i++)
	{
     for(j=0; j<COLS; j++)
     {
#pragma HLS pipeline
	  out1[i][j]=hist_equ1[(inp1[i][j])];
	  out2[i][j]=hist_equ2[(inp2[i][j])];
	  out3[i][j]=hist_equ3[(inp3[i][j])];
	  out4[i][j]=hist_equ4[(inp4[i][j])];
	 }
	}

}



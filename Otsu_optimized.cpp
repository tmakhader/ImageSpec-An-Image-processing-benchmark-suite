#include <iostream>
#include <vector>
#include <math.h>
#include "stdint.h"
#define ROWS 256
#define COLS 256
#define sz ROWS*COLS
    int  total;
    int n=0;
    int m=0;
    int sum_n=0,sum_m=0;
    int rem;
    int rempix;
    float w0;
    float w1;
    float u0;
    float u1;
    int hist_tot;
    static int hist1[256],hist2[256],hist3[256],hist4[256];
float var(int level,float val,int pix_num )
{
    total=pix_num*val;
    n=0;
    m=0;
    hist_tot=(hist1[level-1]+hist2[level-1]+hist3[level-1]+hist4[level-1]);
    sum_m+=(level-1)*hist_tot;
    sum_n+=hist_tot;
    n=sum_n;
    m=sum_m;
    rem=total-m;
    rempix=pix_num-n;
    w0=(1.0*n)/(1.0*pix_num);
    w1=(1.0*rem)/(1.0*pix_num);
    u0=(1.0*m)/(1.0*n);
    u1=(1.0*rem)/(1.0*rempix);
    return (w0*w1*(u0-u1)*(u0-u1));
}
void otsu(int img1[ROWS/4][COLS], int img2[ROWS/4][COLS],int img3[ROWS/4][COLS],int img4[ROWS/4][COLS],
		 bool out1[ROWS/4][COLS], bool out2[ROWS/4][COLS],bool out3[ROWS/4][COLS],bool out4[ROWS/4][COLS])
{
    int8_t u=0,n1,n2,n3,n4;
    for (int i=0;i<ROWS/4;i++)
    {
        for(int j=0;j<COLS;j++)
        {
#pragma HLS pipeline II=2

            n1=img1[i][j];
            n2=img2[i][j];
            n3=img3[i][j];
            n4=img4[i][j];
            hist1[n1]++;
            hist2[n2]++;
            hist3[n3]++;
            hist4[n4]++;
            u+=(n1+n2+n3+n4);
        }
    }
    int pix_num=ROWS*COLS;
    float val=(1.0*u)/float(pix_num);
    float max=0;
    int threshold=0;
    for(int i=1;i<255;i++)
    {
#pragma HLS pipeline
        int x=var(i,val,pix_num);
        if(x>max)
        {
            max=x;
            threshold=i;
        }
    }
    for(int i=0;i<ROWS/4;i++)
    {
#pragma HLS pipeline II=128
        for(int j=0;j<COLS;j++)
        {
            if(img1[i][j]>threshold)
            {
                out1[i][j]=true;
            }
            else
                out1[i][j]=false;
            if(img2[i][j]>threshold)
            {
                out2[i][j]=true;
            }
            else
                out2[i][j]=false;
            if(img3[i][j]>threshold)
            {
                out3[i][j]=true;
            }
            else
                out3[i][j]=false;
            if(img4[i][j]>threshold)
            {
                out4[i][j]=true;
            }
            else
                out4[i][j]=false;
        }
    }
}

#include <iostream>
#include <vector>
#include <math.h>
#define ROWS 256
#define COLS 256
#define sz ROWS*COLS
float var(int hist[],int level,float val,int pix_num )
{
    int  total=pix_num*val;
    int n=0;
    int m=0;
    for(int i=0;i<level;i++)
    {
        m+=i*hist[i];
        n+=hist[i];
    }
    int rem=total-m;
    int rempix=pix_num-n;
    float w0=(1.0*n)/(1.0*pix_num);
    float w1=(1.0*rem)/(1.0*pix_num);
    float u0=(1.0*m)/(1.0*n);
    float u1=(1.0*rem)/(1.0*rempix);
    return w0*w1*(u0-u1)*(u0-u1);
}
void otsu(int img[ROWS][COLS], int out[ROWS][COLS])
{
    int u=0;
    int hist[256];
    for(int i=0;i<256;i++)
        hist[i]=0;
    for (int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            int n=img[i][j];
            u+=n;
            hist[n]++;
        }
    }
    int pix_num=ROWS*COLS;
    float val=(1.0*u)/float(pix_num);
    float max=0;
    int threshold=0;
    for(int i=1;i<255;i++)
    {
        int x=var(hist,i,val,pix_num);
        if(x>max)
        {
            max=x;
            threshold=i;
        }
    }
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(img[i][j]>threshold)
            {
                out[i][j]=255;
            }
            else
                out[i][j]=0;
        }
    }
}

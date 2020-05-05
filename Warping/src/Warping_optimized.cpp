#define COLS 256  //number of columns
#define ROWS 256 //number of rows
#define sx 0
#define sy 0
#define ex 8
#define ey 8
#define preComp1 1/(ex-sx)
#define preComp2 1/(ey-sy)
#define preComp3 preComp1*preComp2
#include <stdio.h>
#include <stdlib.h>


void warp (int Img[ROWS][COLS], int Out[ROWS][COLS],  int Wx[4], int Wy[4])
{
    float a,b,c,d,e,f,i,j,x,y,destX,destY,preX,preY,multX,multY;
    a = (float)(-(Wx[0]) + Wx[1])*preComp2;
    b = (float)(-(Wx[0]) + Wx[3])*preComp1;
    c = (float)((Wx[0]) - Wx[1] + Wx[2] - Wx[3])*preComp3;

    d = (float)(Wx[0]);
    e = (float)(-(Wy[0]) + Wy[1])*preComp1;
    f = (float)(-(Wy[0]) + Wy[3])*preComp2;

    i = (float)((Wy[0]) - Wy[1]+Wy[2]-Wy[3])*preComp3;
    j = (float)(Wy[0]);



    for(y = sy; y < ey; y+=0.5)  
    {
#pragma HLS pipeline
    	preX=b*y+d;
    	preY=f*y+j;
    	multX=c*y+a;
    	multY=i*y+e;
        for(x = sx; x < ex; x+=0.5) 
        {
            destX = (multX*x);
            destY = (multY*x);
            Out[(int)(destY+preY+0.5)][(int)(destX+preX)]=Img[(int)y][(int)(x+0.05)];
        }
    }

}

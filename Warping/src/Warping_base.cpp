#define COLS 256  //number of columns
#define ROWS 256 //number of rows
#define sx 0
#define sy 0
#define ex 8
#define ey 8
#include <stdio.h>
#include <stdlib.h>


void warp (int Img[ROWS][COLS], int Out[ROWS][COLS],  int Wx[4], int Wy[4])
{
    float a,b,c,d,e,f,i,j,x,y,destX,destY;

    a = (float)(-(Wx[0]) + Wx[1])/(ey-sy);
    b = (float)(-(Wx[0]) + Wx[3])/(ex-sx);
    c = (float)((Wx[0]) - Wx[1] + Wx[2] - Wx[3])/((ey-sy)*(ex-sx));

    d = (float)(Wx[0]);
    e = (float)(-(Wy[0]) + Wy[1])/(ex-sx);
    f = (float)(-(Wy[0]) + Wy[3])/(ey-sy);

    i = (float)((Wy[0]) - Wy[1]+Wy[2]-Wy[3])/((ey-sy)*(ex-sx));
    j = (float)(Wy[0]);



    for(y = sy; y < ey; y+=0.5) 
    {
        for(x = sx; x < ex; x+=0.5) 
        {
            destX = (float)(a*x+ b*y+c*x*y+d);
            destY = (float)(e*x+ f*y+i*x*y+j);
            Out[(int)(destY+0.5)][(int)destX]=Img[(int)y][(int)(x+0.05)];
        }
    }

}

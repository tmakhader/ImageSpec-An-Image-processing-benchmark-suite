// Simple line finding Hough Transform
//Inputs: int Img[][],int Acc[][], int threshold

#define ROWS 256
#define COLS 256
#include<stdio.h>
#include<math.h>
#include<stdint.h>
static int16_t Acc1[ROWS/4][COLS],Acc2[ROWS/4][COLS],Acc3[ROWS/4][COLS],Acc4[ROWS/4][COLS];
void hough(bool Img[ROWS][COLS], int16_t thresh, int16_t &theta, int16_t &rho,
		int16_t pre_comp1[ROWS][COLS][ROWS/4],int16_t pre_comp2[ROWS][COLS][ROWS],int16_t pre_comp3[ROWS][COLS][ROWS],
		int16_t pre_comp4[ROWS][COLS][ROWS])
{
	int16_t Thresh1,Thresh2,Thresh3,Thresh4,Rho1,Rho2,Rho3,Rho4;
	int16_t Theta1,Theta2,Theta3,Theta4;
	Thresh1=thresh;
	Thresh2=thresh;
	Thresh3=thresh;
	Thresh4=thresh;
	int16_t i,j,k;
	int16_t trho1,trho2,trho3,trho4;
	// test each image pixel
	for(i=0;i<ROWS;i++)
	{
     for(j=0;j<COLS;j++)
     {
#pragma HLS pipeline II=20
	  if(Img[i][j])
	   {
		 for(k=0;k<ROWS/4;k++)
		  {
			trho1=pre_comp1[i][j][k];
			trho2=pre_comp2[i][j][k];
			trho3=pre_comp3[i][j][k];
			trho4=pre_comp4[i][j][k];
			++(Acc1[k][trho1]);
			++(Acc2[k][trho2]);
			++(Acc3[k][trho3]);
			++(Acc4[k][trho4]);
		  }
		}
	 }
	}

	// scan accumulator for max value
	
	for(i=0;i<ROWS/4;i++)
	{
	 for(j=0;j<COLS;j++)
	 {
#pragma HLS pipeline
	  if(Acc1[i][j]>=Thresh1)
	   {
		Thresh1=Acc1[i][j];
		Rho1=j;
		Theta1=i;
	   }
	  if(Acc2[i][j]>=Thresh2)
	   {
		Thresh2=Acc2[i][j];
		Rho2=j;
		Theta2=64+i;
	   }
	  if(Acc3[i][j]>=Thresh3)
	   {
		Thresh3=Acc3[i][j];
		Rho3=j;
		Theta3=128+i;
	   }
	  if(Acc4[i][j]>=Thresh4)
	   {
		Thresh4=Acc4[i][j];
		Rho4=j;
		Theta4=192+i;
	   }
	 }
	}
    if(Thresh1>=Thresh2 && Thresh1>=Thresh3 && Thresh1>=Thresh4)
    {
     rho=Rho1;
     theta=Theta1;
    }
    else if(Thresh2>=Thresh1 && Thresh2>=Thresh3 && Thresh2>=Thresh4)
    {
     rho=Rho2;
     theta=Theta2;
    }
    else if(Thresh3>=Thresh2 && Thresh3>=Thresh1 && Thresh3>=Thresh4)
    {
     rho=Rho3;
     theta=Theta3;
    }
    else
    {
     rho=Rho4;
     theta=Theta4;
    }
 }
	

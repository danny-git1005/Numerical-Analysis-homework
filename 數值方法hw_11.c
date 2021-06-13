#include <stdio.h>
#include <math.h>
#include "linear.h"

//Gauss-Newton
//
//
// ( Dr(Xk)T Dr(Xk) ) v = -Dr(Xk)T r(Xk)
//
// 		  	 -					-
//		 	| 	ρr1/x	 ρr1/y  |
//	 Dr =   |	ρr2/x	 ρr2/y  |	//對各個變數進行偏微分 
//			|	ρr3/x	 ρr3/y  |
//		 	 - 					-
//	 Xk+1 = Xk + v										
//
main()
{
	int x = 0, y = 0, i = 0, j =0,k = 0;
	matrix D, t_D ,r,vector,t_vector,answer;
	initial(&D,3,2);	initial(&t_D,2,3);
	initial(&r,3,1);
	initial(&vector,2,1);	initial(&t_vector,1,2);		initial(&answer,2,1);
	
	matrix mul1,mul2;
	initial(&mul1,2,2);	initial(&mul2,2,1);
	
	matrix solve;
	initial(&solve,2,3);
	
	scanf("%f %f",&vector.data[0][0],&vector.data[1][0]);
	
	float r_x[3] = {-1,1,1};
	float r_y[3] = {0,1,-1};
	float r1, r2, r3;
	
	for(i = 0;i <10;i++)
	{
		r1 = sqrt(pow(vector.data[0][0]-r_x[0],2) + pow(vector.data[1][0]-r_y[0],2)) - 1;
		r2 = sqrt(pow(vector.data[0][0]-r_x[1],2) + pow(vector.data[1][0]-r_y[1],2)) - 1;
		r3 = sqrt(pow(vector.data[0][0]-r_x[2],2) + pow(vector.data[1][0]-r_y[2],2)) - 1;
		
		r.data[0][0] = r1;	r.data[1][0] = r2;	r.data[2][0] = r3;
		
		D.data[0][0] = (vector.data[0][0] - (-1))/(r1+1);	D.data[0][1] = (vector.data[1][0] - 0)/(r1+1);
		D.data[1][0] = (vector.data[0][0] - 1)/(r2+1);		D.data[1][1] = (vector.data[1][0] - 1)/(r2+1);
		D.data[2][0] = (vector.data[0][0] - 1)/(r3+1);		D.data[2][1] = (vector.data[1][0] - (-1))/(r3+1);
		
		transform(&t_vector, &vector);
		transform(&t_D,&D);				
		mul( &mul1, &t_D, &D );
		mul( &mul2, &t_D, &r );
		
		solve.data[0][0] = mul1.data[0][0];		solve.data[0][1] = mul1.data[0][1];		solve.data[0][2] = (-1)*mul2.data[0][0];
		solve.data[1][0] = mul1.data[1][0];		solve.data[1][1] = mul1.data[1][1];		solve.data[1][2] = (-1)*mul2.data[1][0];
		
		print(&mul1);
		
		gauss( &answer, &solve);
		vector.data[0][0] += answer.data[0][0];
		vector.data[1][0] += answer.data[1][0];
		print(&vector);
		
		for(j = 0;j <mul1.row;j++)
		{
			mul2.data[j][0] = 0;
			for(k = 0; k<mul1.col; k++)
			{
				mul1.data[j][k] = 0;
			}
		}
		
	}
	
	for(i = 0; i<answer.row; i++)
	{
		printf("%f ",vector.data[i][0]);
	}
}

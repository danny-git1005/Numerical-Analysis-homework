#include <stdio.h>
#include <stdlib.h>

//高斯消去法 

void answer(float **matrix, int x,int y);

/*int main ()
{
	float A[4][5] = {
						2,1,0,0,1,
						0,1,2,0,1,
						2,4,5,1,2,
						8,5,0,3,0,
					};
			
	float L[4][4] = {
						1,0,0,0,
						0,1,0,0,
						0,0,1,0,
						0,0,0,1,
					};
	
	int i = 0, j = 0,k = 0,l = 0, m = 0;
	float temp = 0.0;
	
	for(i =0; i < 4; i++)
	{
		for(j = i+1; j<4; j++)
		{
			temp = A[j][i]/A[i][i];
			L[j][i] = temp;
			for( k=i ; k<5; k++)
			{
				A[j][k] = A[j][k] - temp*A[i][k];
			}
		}
	}
	
	float x = 0,y = 0,z = 0,w = 0;
	w = A[3][4]/A[3][3];
	z = (A[2][4] - w*A[2][3])/A[2][2];
	y = (A[1][4] - w*A[1][3]-z*A[1][2])/A[1][1];
	x = (A[0][4] - w*A[0][3]-z*A[0][2]-y*A[0][1])/A[0][0];
	 
	 
	printf("x = %f\n",x);
	printf("y = %f\n",y);
	printf("z = %f\n",z);
	printf("w = %f\n",w);
 
	
	printf("\n");
	printf("L = \n");
	for(i = 0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%f	",L[i][j]);
		}
		printf("\n");
	}
	
	printf("U = \n");
	for(i = 0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%f	",A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
	
 } */
 
 int main ()
 {
 	float **a,**l ;
 	int num1 = 0,num2 = 0,temp = 0.0;
 	int i = 0,j = 0,k = 0;
 	
 	scanf("%d %d",&num1,&num2);
 	
 	a = malloc((num1)*sizeof(float*));
 	l = malloc((num1)*sizeof(float*));
 	
	for(i = 0;i < num1; i++)
	{
		a[i] = calloc(num1+1,sizeof(float));
	}
	
	for(i = 0;i < num1; i++)
	{
		l[i] = calloc(num1,sizeof(float));
	}
	
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1+1; j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1; j++)
		{
			if(i == j)
			{
				l[i][j] = 1 ;			
			}
			else
			{
				l[i][j] = 0 ;			
			}			
		}
	}
	
	for(i = 0; i < num1; i++)
	{
		for(j = i+1; j<num1; j++)
		{
			temp = a[j][i]/a[i][i];
			l[j][i] = temp;
			for( k=i ; k<num1+1; k++)
			{
				a[j][k] = a[j][k] - temp*a[i][k];
			}
		}
	}
	
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1+1; j++)
		{
			printf("%f ",a[i][j]);
		}
		printf("\n");
	}
 	
 	return 0;
 }
 
/*
4 5
2 1 0 0 1
0 1 2 0 1 
2 4 5 1 2 
8 5 0 3 0  
*/ 
 
 
 
 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void answer(float **matrix, int x,int y);
void permutation(float **matrix, float **p, int column, int num );

//高斯消去加上partial pivoting 

 int main ()
 {
 	float **a,**l ,**p;
 	float temp= 0.0;
 	int num1 = 0,num2 = 0;
 	int i = 0,j = 0,k = 0;
 	
 	scanf("%d %d",&num1);				//輸入變數數量 
 	
 	a = malloc((num1)*sizeof(float*));
 	l = malloc((num1)*sizeof(float*));
 	p = malloc((num1)*sizeof(float*));
 	
	for(i = 0;i < num1; i++)
	{
		a[i] = calloc(num1+1,sizeof(float));
	}
	
	for(i = 0;i < num1; i++)
	{
		l[i] = calloc(num1,sizeof(float));
		p[i] = calloc(num1,sizeof(float));
	}
	
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1+1; j++)
		{
			scanf("%f",&a[i][j]);				//輸入方程式 
		}
	}
	
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1; j++)
		{
			if(i == j)
			{
				l[i][j] = 1 ;	p[i][j] = 1 ;
			}
			else
			{
				l[i][j] = 0 ;	p[i][j] = 0 ;	
			}			
		}
	}
	int q = 0, o = 0;
	
	for(i = 0; i < num1; i++)
	{
		if( i != num1-1)
		{
			permutation(a, p, num1, i );
		}
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
	
 	
 	float x = 0.0,y = 0.0,z = 0.0,w = 0.0;
	w = a[3][4]/a[3][3];
	z = (a[2][4] - w*a[2][3])/a[2][2];
	y = (a[1][4] - w*a[1][3]-z*a[1][2])/a[1][1];
	x = (a[0][4] - w*a[0][3]-z*a[0][2]-y*a[0][1])/a[0][0];
	 
	 
	printf("x = %f\n",x);
	printf("y = %f\n",y);
	printf("z = %f\n",z);
	printf("w = %f\n",w);
 
 
 	printf ("A = \n");
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1+1; j++)
		{
			printf("%f ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("L = \n");
	for(i = 0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%f	",l[i][j]);
		}
		printf("\n");
	}
	
	printf("U = \n");
	for(i = 0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%f	",a[i][j]);
		}
		printf("\n");
	}
	
	printf("P = \n");
	for(i = 0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%f	",p[i][j]);
		}
		printf("\n");
	}
	return 0;
 }
 
 void permutation(float **matrix, float **p, int column, int num )
 {
 	int i = 0, j = 0,word = 0,temp1 = 0;
	float max = 0.0 ;	
 	float temp = 0.0;
 	
 	for( i = num ; i < column; i++)
 	{
 		if( fabs(matrix[i][num]) > abs(max) )
 		{
 			max = matrix[i][num];
 			word = i;
		}
	}
	
	printf("num = %d \n",num);
	printf("word = %d\n", word );
	
	for( j = num; j < column+1 ;j++ )
	{
		temp = matrix[num][j] ; 
		matrix[num][j] = matrix[word][j];
		matrix[word][j] = temp;
	}
	
	for( j = 0; j < column ;j++ )
	{
		temp1 = p[num][j];
		p[num][j] = p[word][j];
		p[word][j] = temp1;
	}
	
	
	
	printf("P = \n");
	for( i = 0 ;i < column ; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%f ",p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 }
 
 
/*
4 5
2 1 0 0 1
0 1 2 0 1 
2 4 5 1 2 
8 5 0 3 0  
*/ 
 
 /*
 4 5
 4.0 2.0 -1.0 3.0 16.9
 3.0 -4.0 2.0 5.0 -14.0
 -2.0 6.0 -5.0 -2.0 25.0
 5.0 1.0 6.0 -3.0 9.4
 */
 
 
 

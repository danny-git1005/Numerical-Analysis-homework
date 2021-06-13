#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Jacobi 

void jacobi(float **L,float **D,float **U, float *C,int number);
void mul(float **a,float *b,float *ans,int row1,int col1);

 int main ()
 {
 	float **l=NULL,**d= NULL,**u=NULL,*c=NULL;
 	float temp= 0.0;
 	int num1 = 10,num2 = 0;
 	int i = 0,j = 0,k = 0;
 	
 	//scanf("%d",&num1);						//輸入變數數量 
 	
 	d = malloc((num1)*sizeof(float*));
 	l = malloc((num1)*sizeof(float*));
 	u = malloc((num1)*sizeof(float*));
 	c = calloc(num1,sizeof(float));
	
	for(i = 0;i < num1; i++)
	{
		d[i] = calloc(num1,sizeof(float));
		l[i] = calloc(num1,sizeof(float));
		u[i] = calloc(num1,sizeof(float));
	}
	
	for(i = 0;i < num1; i++)
	{
		for(j = 0;j < num1+1; j++)
		{
			if( j == num1)
			{
				scanf("%f", &c[i]);
			}	
			else if( i == j)
			{
				scanf("%f", &d[i][j]);
			}
			else if( i < j )
			{
				scanf("%f", &u[i][j]);
			}
			else
			{
				scanf("%f", &l[i][j]);
			}
		}
	}
	
	jacobi(l,d,u,c,num1);
	
	return 0;	
 }
 
 void mul(float **a,float *b,float *ans,int row1,int col1)
 {
 	int i = 0,j = 0;
 	for(j = 0; j < row1;j++)
	{
		ans[j] = 0; 
	}
 	for(i = 0 ; i< row1;i++)
 	{
 		for(j = 0; j < col1;j++)
 		{
 			ans[i] = ans[i]+a[i][j]*b[j]; 
		}
	 }
 }
 
 void jacobi(float **L,float **D,float **U, float *C,int number)
 {
 	float *guess = calloc(number,sizeof(float));
 	float *temp = calloc(number,sizeof(float));
 	float *answer = calloc(number,sizeof(float));
 	float *store = calloc(number,sizeof(float));
 	int i =0 , j = 0;
 	float n = 0;
 	
 	for( i = 0 ; i<number; i++)
 	{
 		for(j = 0 ; j<number; j++)
 		{
 			L[i][j] = L[i][j] + U[i][j]; 
 			if( i == j)
 			{
 				D[i][j] = 0.3333333333;
			}
		 }
	}
	 

 	while(1)
 	{
 		for(i = 0 ;i < number ; i++)
		{
			printf("%f\n", temp[i]);
		}
		printf("\n");
 		mul(L,guess,temp,number,number);
 		for(i = 0 ;i < number ; i++)
		{
			printf("%f\n", temp[i]);
		}
		printf("\n");
 		for(i =0 ; i< number; i++)
 		{
 			store[i] = C[i] - temp[i];
 			temp[i] = 0;
		}
		/*for(i = 0 ;i < number ; i++)
		{
			printf("%f\n", temp[i]);
		}
		printf("\n");*/
		mul(D,store,temp,number,number);
		for(i =0 ; i< number; i++)
 		{
 			guess[i] = temp[i];
		}
		
		for( i = 0 ; i < number ; i++)
		{
			n = n + guess[i] - answer[i];
		}
	
		if(n/10 < 0.00000001)
		{
			for(i = 0 ;i < number ; i++)
			{
				printf("%f\n", guess[i]);
			}
			break;
		}
		printf("guess = \n");
		for(i = 0 ;i < number ; i++)
		{
			printf("%f\n", guess[i]);
		}
		printf("\n");
		for( i = 0 ; i < number ; i++)
		{
			answer[i] = temp[i];
		}
		n = 0;
		
	 }
 }
 
 
 /*
 10
 3 -1 0 0 0 0 0 0 0 0 2
 -1 3 -1 0 0 0 0 0 0 0 1
 0 -1 3 -1 0 0 0 0 0 0 1
 0 0 -1 3 -1 0 0 0 0 0 1
 0 0 0 -1 3 -1 0 0 0 0 1
 0 0 0 0 -1 3 -1 0 0 0 1
 0 0 0 0 0 -1 3 -1 0 0 1
 0 0 0 0 0 0 -1 3 -1 0 1
 0 0 0 0 0 0 0 -1 3 -1 1
 0 0 0 0 0 0 0 0 -1 3 2
 */
 
 
 
 
 
 

 

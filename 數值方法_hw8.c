#include <stdio.h>
#include <stdlib.h>

///Newton¡¦s divided
//
// X1 | Y1
//			f[X1 X2]
// X2 | Y2			 f[X1 X2 X3]
//			f[X2 X3]			f[X1 X2 X3 X4]
// X3 | Y3			 f[X1 X2 X3]
//			f[X2 X4]
// X4 | Y4 
//
//
//
main()
{
	int number = 0,i = 0,j = 0,count = 0;			
	
	printf("input your data scale:");
	scanf("%d",&number); 
	
	float *x,*y,**step;			x = calloc(number,sizeof(float));	y = calloc(number,sizeof(float));	step = calloc(number,sizeof(float*));
	float require = 0.0, answer = 0.0, temp = 1.0;
	
	printf("input your data:");
	for(i = 0; i< number; i++)
	{
		scanf("%f %f",&x[i],&y[i]);
	}
	printf("input your answer:");
	scanf("%f",&require);
	for(i = 0; i< number; i++)
	{
		step[i] = calloc(number,sizeof(float));
	}
	
	while( count < number )
	{
		for(i = 0; i < number - count; i++)
		{
			if( count == 0 )
			{
				step[i][count] = y[i];
			}
			else
			{
				step[i][count] = (step[i+1][count-1] - step[i][count-1])/(x[i+count] - x[i]);
			}
		}
		count++;
	}
	
	for(i = 0; i<number ; i++ )
	{
		if(i == 0 )
		{
			answer += step[0][i];
		}
		else
		{
			for(j = 0; j<i ; j++ )
			{
				temp *= require - x[j]; 
			}
			temp *= step[0][i];
			answer += temp;
			temp = 1; 	
		}
	}
	
	printf("%f",answer);
	
 }

/*
4
1800 280
1850 283
1900 291
2000 370
1950
*/
/*

0 1
2 2
3 4
1 0
*/
 /*
main()
{
	float x[4] = {1800,1850,1900,2000};
	float y[4] = {280,283,291,370};
	float req = 1950;
	
	float first[4] = {280,283,291,370};
	float second[3] = {0};
	float third[2] = {0};
	float fourth[1] = {0};
	float answer = 0;
	int i = 0;
	
	for( i = 0; i< 3 ; i++)
	{
		second[i] = (first[i+1] - first[i])/(x[i+1] - x[i]);
	}
	for( i = 0; i < 2; i++)
	{
		third[i] = (second[i+1] - second[i])/(x[i+2] - x[i]);
	}
	
	fourth[0] = (third[1] - third[0])/(x[3] - x[0]);
	
	answer = first[0] + second[0]*(req - x[0]) + third[0]*(req - x[0])*(req - x[1]) + fourth[0]*(req - x[0])*(req - x[1])*(req - x[2]);
	
	printf("%f\n",first[0]);
	printf("%f\n",second[0]);
	printf("%f\n",third[0]);
	printf("%f\n",fourth[0]);
	printf("%f",answer);
	
	
 } 
*/
 
 
 

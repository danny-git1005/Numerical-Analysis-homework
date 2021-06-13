#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//Lagrange interpolation
//
//
//			  (X - X2)(X - X3)		     (X - X1)(X - X3)	      (X - X1)(X - X3)
// P(x) = Y1 ---------------------  + Y2------------------- + Y3---------------------
//			  (X1 - X2)(X1 - X3)	     (X2 - X1)(X2 - X3)	     (X3 - X1)(X3 - X2)
//
//
main ()
{
	int number = 0;
	int i = 0,j = 0;
	double *x,*y;
	double answer = 0,target = 0,temp = 1; 	
	//double first = 0, second = 0, third = 0, fourth = 0,temp = 1;
	//double constant1 = 3039585530 , constant2 = 3707475887,constant3 = 5281653820,constant4 = 6079603571;
	
	printf("input your data row number:");
	scanf("%d",&number);
	
	x = calloc(number, sizeof(double));
	y = calloc(number, sizeof(double));
	
	for(i = 0; i<number ; i++)
	{
		scanf("%lf %lf",&x[i],&y[i]);
	}
	printf("input which x you want to know:");
	scanf("%lf",&target);
	
	for(i = 0; i<number; i++)
	{
		for(j = 0; j<number ; j++ )
		{
			if( j != i )
			{
				temp *= (target - x[j])/(x[i] - x[j]);
			}
		}
		temp *= y[i];
		answer += temp;
		temp = 1;
	}
	for(i = 0; i<number ; i++)
	{
		printf("%lf %lf\n",x[i],y[i]);
	}
	printf("%lf",answer);
	/*
	first = constant1*(10)*(-10)*(-20) /(-10)/(-30)/(-40);
	second = constant2*(year - 1960)*(year - 1990)*(year - 2000)/ (10)/(-20)/(-30);
	third = constant3*(year - 1960)*(year - 1970)*(year - 2000)/ (-10)/(20)/(30);
	fourth = constant4*(year - 1960)*(year - 1970)*(year - 1990)/ (10)/(30)/(40);

	answer = first + second + third + fourth;
	printf("%lf",answer); 
	*/
}
 
 /*
1960 3039585530
1970 3707475887
1990 5281653820
2000 6079603571

1980
*/
/*
-5 5
-4 5
-3 5
-2 5
-1 5
0 5
1 5
2 5
3 5
4 5
5 42

6
*/




#include <stdio.h>
#include <math.h>

//¤û¹yªk 

main ()
{
	double x = 3.0 , temp = 0.0;
	
	while(1)
	{
		temp =  (pow(x,5) + x - 3)/(5*pow(x,4)+1);
		printf("x = %lf , temp = %lf\n",x,temp);
		if( temp < 0.00001 )
		{
			break;
		}
		
		x = x - temp;
		
	}
	
	printf("No1 : %lf\n",x);
	
	x = 2.0 ,temp = 0.0;
	while(1)
	{
		temp =  (log(x) + 2*x*x - 3 )/ ( 1/x + 4*x );
		printf("x = %lf , temp = %lf\n",x,temp);
		if( temp < 0.00001 )
		{
			break;
		}
		
		x = x - temp;
		
	}
	
	printf("No2 : %lf",x);
 } 

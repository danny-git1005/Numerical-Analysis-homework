#include <stdio.h>
#include <math.h>

main ()
{
	double a,b;
	double up = 3, down = 2, mid, temp;		//宣告需要的上界下界 
	
	while(1) 			//第一題 
	{
		mid = (up + down)/2;	
		temp = pow(mid,3)-9;				// 將值重複帶入方程式 
		
		if( temp > 0)
		{
			up = mid;
		}
		else if( temp < 0)
		{
			down = mid;
		}
		
		if( up - down < 0.00001)			//若值小於設定則代表接近需要的答案 
		{
			break;
		}
	}

	double up1 = 4, down1 = 3, mid1, temp1; 

	while(1) 			//第二題 
	{
		mid1 = (up1 + down1)/2;	
		temp1 = mid1-pow(mid1,0.3333333333333)-2;	
		
		if( temp1 > 0)
		{
			up1 = mid1;
		}
		else if( temp1 < 0)
		{
			down1 = mid1;
		}
		
		if( up1 - down1 < 0.000000001)
		{
			break;
		}
	}
	
	printf("\n%lf\n",mid);
	printf("%lf",mid1);
	
 } 
 
 
 
 
 //x^3-9 = 0
 //x-x^1/3-2 = 0  3<x<4
 
 
 

#include <stdio.h>
#include "linear.h"

//QR Factorization

int main ()
{
	matrix a,b,c;
	int i = 5,j = 5, row = 0, col = 0;
	
	
	initial(&a,4,3);
	scan(&a);
	
	QR_factorize(&a);
		
	return 0;
} 

/*
1 -1 4
1 4 -2
1 4 2
1 -1 0

*/  

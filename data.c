#include <stdio.h>
#include <math.h>

main()
{
	int i = 0;
	
	for(i = 1;i<=12;i++)
	{
		printf("1	%f	%f	%f\n",cos(2*M_PI*i/12),sin(2*M_PI*i/12),cos(4*M_PI*i/12));
	}
	
}

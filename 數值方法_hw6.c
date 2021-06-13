#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//
//
// Df(Xk) s = - F(Xk)
//
//	Xk+1 = Xk + s
//
//
//

typedef struct matrix
{
	int col;
	int row;
	float **data;
 }matrix;
void initial(matrix *a,int row_num,int col_num);
void PLU(matrix *p, matrix *l, matrix *u, matrix *a);
void permut(matrix *a, matrix *p, int num);
void gauss( matrix *a, matrix *answer)	;
void print(matrix *a);


int main ()
{
	matrix ans,temp,f,d;
	int i = 5,j = 5, row = 0, col = 0;
	
	initial(&ans,3,1);
	initial(&temp,3,1);
	initial(&d,3,4);
	initial(&f,3,1);
	
	ans.data[0][0] = 0;
	ans.data[1][0] = 0;
	ans.data[2][0] = 1;
	
	for(i = 0; i<20; i++)
	{
		//對三個函式的三個變數進行偏微分 
		d.data[0][0] = 1;
		d.data[0][1] = 1;
		d.data[0][2] = 1;
		d.data[1][0] = 2*ans.data[0][0];
		d.data[1][1] = 2*ans.data[1][0];
		d.data[1][2] = 2*ans.data[2][0];
		d.data[2][0] = exp(ans.data[0][0]) + ans.data[1][0] - ans.data[2][0];
		d.data[2][1] = ans.data[1][0];
		d.data[2][2] = -(ans.data[1][0]);
		//將函示代入猜測值 
		f.data[0][0] = ans.data[0][0] + ans.data[1][0] + ans.data[2][0] - 3;
		f.data[1][0] = pow(ans.data[0][0],2) + pow(ans.data[1][0],2) + pow(ans.data[2][0],2)-5;
		f.data[2][0] = exp(ans.data[0][0]) + ans.data[0][0]*ans.data[1][0] - ans.data[0][0]*ans.data[2][0] - 1;
		//f.data 值 放入d.data來進行高斯解 
		d.data[0][3] = (-1.0)*f.data[0][0];
		d.data[1][3] = (-1.0)*f.data[1][0];
		d.data[2][3] = (-1.0)*f.data[2][0];		
		
		gauss(&d,&temp);
		
		for(j = 0; j<3 ;j++)
		{
			ans.data[j][0] += temp.data[j][0];
			temp.data[j][0] = 0;
		}
	}

	print(&ans);
	return 0;
} 
void initial(matrix *a,int row_num,int col_num)			//將矩陣初始化 
{
	int i = 0,j = 0;
	
	a->row = row_num;
	a->col = col_num;
	a->data = malloc((a->row)*sizeof(float*));
	
	for(i = 0; i<a->row ; i++ )
	{
		a->data[i] = calloc(a->col,sizeof(float));
	}
}

void PLU(matrix *p, matrix *l, matrix *u, matrix *a)
{
	int i = 0, j = 0,k = 0;
	float temp = 0.0;
	
	for(i =0; i < a->row; i++)
	{
		if(p != NULL)
		{
			permut(a,p,i);
		}
		for(j = i+1; j<a->row; j++)
		{
			temp = a->data[j][i]/a->data[i][i];
			if(l != NULL)
			{
				l->data[j][i] = temp;
			}
			for( k=i ; k<a->col; k++ )
			{
				a->data[j][k] = a->data[j][k] - temp*a->data[i][k];	
			}
		}
	}
	
	if (u != NULL)
	{
		for(i = 0; i<u->row; i++ )
		{
			for(j = 0; j<u->col; j++)
			{
				u->data[i][j] = a->data[i][j];
			}
		}
	}
}

void permut(matrix *a, matrix *p, int num)		//需傳入要計算的矩陣a  
{
	int i = 0, j = 0,word = 0,temp1 = 0;
	float max = 0.0 ;	
 	float temp = 0.0;
 	
 	for( i = num ; i < a->row; i++)
 	{
 		if( fabs(a->data[i][num]) > fabs(max) )
 		{
 			max = a->data[i][num];
 			word = i;
		}
	}

	for( j = num; j < a->col ;j++ )
	{
		temp = a->data[num][j] ; 
		a->data[num][j] = a->data[word][j];
		a->data[word][j] = temp;
	}
	
	for( j = 0; j < a->col ;j++ )
	{
		temp1 = p->data[num][j];
		p->data[num][j] = p->data[word][j];
		p->data[word][j] = temp1;
	}
}

void gauss( matrix *a, matrix *answer)						//高斯消去法 : 傳進來的矩陣必須變數數量跟方程式數量一樣
{
	int i = 0, j = 0,k = 0;
	float temp = 0.0;
	//float *answer = calloc(a->row,sizeof(float));
	matrix p, l, u;
	initial(&p,a->row,a->row);
	initial(&l,a->row,a->row);
	initial(&u,a->row,a->row);
	
	for(i = 0; i<a->row;i++)
	{
		for(j = 0; j<a->row; j++ )
		{
			if(i == j)
			{
				l.data[i][j] = 1 ;	p.data[i][j] = 1 ;
			}
			else
			{
				l.data[i][j] = 0 ;	p.data[i][j] = 0 ;	
			}
		}
	}
	
	PLU(&p,&l,&u,a);

	for(i = a->row-1; i >= 0; i--)
	{
		for(j = a->row-1; j>i; j--)
		{
			a->data[i][a->col-1] = a->data[i][a->col-1] - answer->data[j][0]*a->data[i][j];
		}
		answer->data[i][0] = a->data[i][a->col-1]/a->data[i][i];
		//printf("i = %d, %f %f\n",i,a->data[i][a->col-1],a->data[i][i]);
	}
	//print(a);
	
	for(i = 0; i < a->row; i++)
	{
		//printf("%f\n",answer->data[i][0]);	
	}
	printf("\n");
	
}
void print(matrix *a)									//列印矩陣資料 
{
	int i = 0,j = 0;
	
	for(i = 0;i < a->row; i++)
	{
		for(j =0 ; j<a->col; j++)
		{
			printf("%f ",a->data[i][j]);
		}
		printf("\n");
	}
}
/*


0 1 2
2 4 5
8 5 0

1 0
1 0
1 0

4
1 0 0 1 2
-1 1 0 0 0
-1 -1 1 1 0
-1 -1 -1 1 -2
*/  

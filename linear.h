#ifndef _LINEAR_H_
#define _LINEAR_H_

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct matrix
{
	int col;
	int row;
	float **data;
 }matrix; 

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

void freematrix(matrix *a)
{
	int i = 0;
	
	for(i = 0;i<a->row; i++)
	{
		free(a->data[i]);
	}
}

void scan(matrix *a)									//掃描矩陣資料 
{
	int i = 0,j = 0;
	
	for(i = 0;i < a->row; i++)
	{
		for(j =0 ; j<a->col; j++)
		{
			scanf("%f",&a->data[i][j]);
		}
	}
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

void transform(matrix *b, matrix *a)						// 變換矩陣 
{
	int i = 0,j = 0;
	for(i = 0; i<a->row;i++)
	{
		for(j = 0; j<a->col; j++ )
		{
			b->data[j][i] = a->data[i][j];
		}
	 } 
}

void add( matrix *a, matrix *b, matrix *c )				//矩陣加法 a = b + c
{
	int i , j;
	
	for(i = 0;i<a->row;i++)
	{
		for(j = 0; j<a->col; j++)
		{
			a->data[i][j] = b->data[i][j] + c->data[i][j];
		}
	}
}

void sub( matrix *a, matrix *b, matrix *c )				//矩陣減法 a = b - c
{
	int i, j, k;
	
	for(i = 0;i<b->row;i++)
	{
		for(j = 0; j<b->col; j++)
		{
			a->data[i][j] = b->data[i][j] - c->data[i][j];
		}
	}
}

void mul( matrix *a, matrix *b, matrix *c )				//矩陣乘法 a = b * c
{
	int i , j , k;
	for(i = 0;i<b->row;i++)
	{
		for(j = 0; j<c->col; j++)
		{
			for(k = 0; k<b->col; k++)
			{
				a->data[i][j] = a->data[i][j] + b->data[i][k]*c->data[k][j];
			}
		}
	}
}

void permut(matrix *a, matrix *p, int num)				//需傳入要計算的矩陣a  
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

void gauss( matrix *ans,matrix *a)									//高斯消去法 : 傳進來的矩陣必須變數數量跟方程式數量一樣
{
	int i = 0, j = 0,k = 0;
	float temp = 0.0;
	float *answer = calloc(a->row,sizeof(float));
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
	//printf("\nP = \n");	print(&p);
	//printf("\nL = \n");	print(&l);
	//printf("\nU = \n");	print(&u);
	
	for(i = a->row-1; i >= 0; i--)
	{
		for(j = a->row-1; j>i; j--)
		{
			a->data[i][a->col-1] = a->data[i][a->col-1] - answer[j]*a->data[i][j];
		}
		answer[i] = a->data[i][a->col-1]/a->data[i][i];
	}
	for(i = 0; i < a->row; i++)
	{
		printf("i = %d\n",i);
		ans->data[i][0] = answer[i];
	}
	print(ans);
}

void jacobi(matrix *a)
{
	int i = 0, j = 0;
	float *c=NULL,n = 0;
	
 	matrix guess; initial(&guess,a->row,1);
 	matrix temp; initial(&temp,a->row,1);
 	matrix answer; initial(&answer,a->row,1);
 	matrix store; initial(&store,a->row,1);
	
	matrix d ; initial(&d,a->row,a->row);
	matrix l ; initial(&l,a->row,a->row);
	matrix u ; initial(&u,a->row,a->row);
 	c = calloc(a->row,sizeof(float));
 	
	for(i = 0;i < a->row; i++)
	{
		for(j = 0;j < a->col; j++)
		{
			if( j == a->col-1)
			{
				c[i] = a->data[i][j];
			}	
			else if( i == j)
			{
				d.data[i][j] = a->data[i][j];
			}
			else if( i < j )
			{
				u.data[i][j] = a->data[i][j];
			}
			else
			{
				l.data[i][j] = a->data[i][j];
			}
		}
	}
	
	for( i = 0 ; i<a->row; i++)
 	{
 		for(j = 0 ; j<a->row; j++)
 		{
 			l.data[i][j] = l.data[i][j] + u.data[i][j]; 
 			if( i == j )
 			{
 				d.data[i][j] = 1.0/d.data[i][j];
			}
		}
	}
	
	int w = 0;
	for(w= 0 ; w < 1000; w++)
 	{
 		mul(&temp,&l,&guess);
 		for(i =0 ; i< a->row; i++)
 		{
 			store.data[i][0] = c[i] - temp.data[i][0];
 			temp.data[i][0] = 0;
		}
		
		mul(&temp,&d,&store);
		for(i =0 ; i< a->row; i++)
 		{
 			guess.data[i][0] = temp.data[i][0];
		}
		
		for( i = 0 ; i < a->row ; i++)
		{
			n = n + guess.data[i][0] - answer.data[i][0];
		}
		
		for( i = 0 ; i < a->row ; i++)
		{
			answer.data[i][0] = temp.data[i][0];
			temp.data[i][0] = 0;
		}
		n = 0;
	 }
	for(i = 0 ;i < a->row ; i++)
	{
		printf("%f\n", guess.data[i][0]);
	}
}

void least_squre(matrix *a, matrix *common)
{
	matrix b,c,d,e;
	matrix answer;
	int i = 0,j = 0;
	float temp = 0;
	initial(&b,a->col,a->row);
	initial(&c,b.row,a->col);
	initial(&d,b.row,1);
	initial(&e,a->col,a->col+1);
	initial(&answer,a->row,1);
	
	transform(&b,a);
	mul(&c,&b,a);
	mul(&d,&b,common);
	
	
	for(i = 0 ; i<c.row ; i++ )
	{
		for(j = 0; j<c.col+1; j++)
		{
			e.data[i][j] = c.data[i][j];
		}
	}
	for(i = 0 ; i<c.row ; i++ )
	{
		e.data[i][e.col-1] = d.data[i][0];
	}
	
	gauss(&answer,&e);
}

void QR_factorize(matrix *a)
{
	int i = 0, j = 0, k = 0;
	float len = 0,store = 0;;
	
	matrix Q,R;
	matrix q,q_t,a_t,y_t;
	matrix temp1,temp2,temp3,temp4;
	initial(&Q,a->row,a->col);	initial(&R,a->col,a->col);		initial(&y_t,a->row,1);
	initial(&q,a->row,1);		initial(&q_t,1,a->row);			initial(&a_t,a->row,1);		
	initial(&temp1,1,1);	initial(&temp2,a->row,1);	initial(&temp3,a->row,1);	initial(&temp4,a->row,1);
	
	
	for(i = 0; i<a->col ; i++ )
	{	
		if(i == 0)
		{
			for(j = 0;j<a->row ; j++ )
			{
				
				len += pow(a->data[j][i],2);
				y_t.data[j][i] = a->data[j][i];
			}

			len = sqrt(len);
			R.data[i][i] = len;
			for(j = 0;j<a->row ; j++ )
			{
				Q.data[j][i] = a->data[j][i]/len;
			}
		}
		else
		{
			for( j = 0; j<i; j++ )
			{	
				for(k = 0; k<q.row ;k++ )
				{
					q.data[k][0] = Q.data[k][j];
					a_t.data[k][0] = a->data[k][i];
				}
				
				transform(&q_t, &q);
				mul( &temp1, &q_t, &a_t);
				R.data[j][i] = temp1.data[0][0];
				mul(&temp2,&q,&temp1);
				add( &temp3, &temp4, &temp2 );
				temp1.data[0][0] = 0;
			}
			
			for( k = 0; k<Q.row ;k++)
			{
				a_t.data[k][0] = a->data[k][i];
			}
			sub(&temp2 , &a_t, &temp3);	
			len = 0;
			for( k = 0; k<temp2.row ;k++)
			{
				len += pow(temp2.data[k][0],2);
			}
			len = sqrt(len);
			R.data[i][i] = len;
			for( k = 0; k<Q.row ;k++)
			{
				Q.data[k][i] = temp2.data[k][0]/len;
			}
			for( k = 0; k<a->row ;k++)
			{
				temp3.data[k][0] = 0;
				temp2.data[k][0] = 0;
				temp1.data[0][0] = 0;
				q_t.data[0][k] = 0;
				q.data[k][0] = 0;
			}
		}

	}
	printf("Q = \n");	print(&Q);	printf("\n");
	printf("R = \n");	print(&R);	printf("\n");
}
	

#endif






#include <stdio.h>
#include <stdlib.h>


double** topelitz(double* a, double* b,int a_size,int b_size)
{
	double** ans = (double**)malloc((a_size+b_size-1) * sizeof(double*));
    int i;
    for (i = 0; i < a_size+b_size-1; i++)
        ans[i] = (double*)malloc(b_size * sizeof(double));
	for(int i=0;i<b_size;i++){
		for(int j=i;j<i+a_size;j++){
			ans[j][i] = a[j-i];
		}
	}
	return ans;
}

double* mul(double** mat, double a[], int a_size, int b_size)
{
	double* ans;
	int mat_col_size = a_size + b_size - 1;
	int mat_row_size = b_size;
	ans = (double*)malloc((a_size+b_size-1) * sizeof(double));
	if(mat_row_size!=b_size) return ans;
	for(int i=0;i<mat_col_size;i++){
		double temp=0;
		for(int j=0;j<b_size;j++){
			temp+=(mat[i][j]*a[j]);
		}
		ans[i] = temp;	
	}
	return ans;
}

double* convulution(double a[], double b[],int a_size,int b_size)
{
	return mul(topelitz(a,b,a_size,b_size), b, a_size, b_size);
}

int main()
{
	FILE *fp;
	fp = fopen("values.txt","w");
	int n=6;
	int k=20;
	double *x,*y;
	x = (double*)malloc(n * sizeof(double));
	for(int i=1;i<=6;i++){
		if(i%4!=0) x[i-1] = i%4;
		else x[i-1] = i;
	}
	y = (double*)malloc(k * sizeof(double));
	y[0]=x[0];
	y[1]=-0.5*y[0]+x[1];
	for(int i=2;i<k-1;i++){
		if(i<6){
			y[i] = -0.5*y[i-1]+x[i]+x[i-2];
		}
		else if(i>5 && i<8){
			y[i] = -0.5*y[i-1]+x[i-2];
		}
		else{
			y[i] = -0.5*y[i-1];
		}
	}
	double* conv = convulution(x,y,6,20);
	for(int i = 0; i < 20; i++)
	{
		fprintf(fp, "%f ", y[i]);
	}
	fclose(fp);

	return 0;
}

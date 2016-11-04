#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "matrix.h"

bool get_rows(Matrix *matrix,FILE *fo)
{
	return (fscanf(fo,"%d", &(matrix->rows)) == 1);
}

int get_cols(Matrix* matrix,FILE *fo)
{
	return (fscanf(fo,"%d", &(matrix->cols))==1);	
}

void create_matrix(Matrix* matrix,FILE *fo)
{
	matrix->Buffer= (int**)malloc((matrix->rows+1)*sizeof(int*));

	for(int i=0;i<matrix->rows+1;i++)
	{
		matrix->Buffer[i]=(int*)malloc((matrix->cols+1)*sizeof(int*));
	}

	int row;
	int col;
	int val;

	for(int i=0;i<(matrix->rows)*(matrix->cols);i++)
	{
		fscanf(fo,"%d %d %d", &row,&col,&val);
		matrix->Buffer[row][col]=val;
	}
}	

void set_elem(Matrix* matrix, int row1, int col1, int val1)
{
	matrix->Buffer[row1][col1]=val1;
}

int get_elem(Matrix* matrix, int row1, int col1){
	return (matrix->Buffer[row1][col1]);
}

void multiplication(Matrix* matrix1,Matrix* matrix2,Matrix* matrix3){

	for(int i=0;i<matrix1->rows;i++)
	{
		for(int j=0;j<matrix2->cols;j++)
		{
			for(int k=0;k<matrix1->rows;k++)
			{
				matrix3->Buffer[i][j]+=matrix1->Buffer[i][k]*matrix2->Buffer[k][j];
				printf("%d",matrix3->Buffer[i][j]);
				printf(" ");
			}
			printf("\n");
		}
					
}

void free_matrix(Matrix* matrix)
{
	for(int i=0;i<matrix->cols+1;i++)
	{
		free(matrix->Buffer[i]);
	}
	free(matrix->Buffer);
}

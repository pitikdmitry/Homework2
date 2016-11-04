#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "matrix.h"

typedef struct Matrix {
	int **Buffer;
    int rows;
	int cols;
}Matrix;

void multiplication(Matrix* matrix1,Matrix* matrix2,Matrix* matrix3);
void create_matrix(Matrix* matrix,FILE *fo);
int get_elem(Matrix* matrix, int row, int col);
void set_elem(Matrix* matrix, int row1, int col1, int val1);
bool get_rows(Matrix* matrix,FILE *fo);
int get_cols(Matrix* matrix,FILE *fo);
void free_matrix(Matrix* matrix);
#endif //_MATRIX_H_

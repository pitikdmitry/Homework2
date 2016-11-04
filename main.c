//Homework2 Var1
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "matrix.h"

int main(int argc, char *argv[]){
	 if (argc != 4) {
        printf("Usage: %s number_of_words_to_generate\n", argv[0]);
        return EXIT_FAILURE;
    }

	Matrix matrix1;

	FILE *f1=fopen(argv[1],"r");
	if (f1==NULL){
		printf("cant open file");
		exit(1);	
	}
	if(get_rows(&matrix1,f1)==0){
		exit(1);
	}
	if(get_cols(&matrix1,f1)==0){
		exit(1);
	}

	create_matrix(&matrix1,f1);
	
	fclose(f1);

	Matrix matrix2;
	
	FILE *f2=fopen(argv[2],"r");
	if (f2==NULL){
		printf("cant open file");
		exit(1);	
	}
	
	if(!get_rows(&matrix2,f2))
	{
		printf("error");
		exit(1);
	}
	if(!get_cols(&matrix2,f2))
	{
		printf("error");
		exir(1);
	}
	create_matrix(&matrix2,f2);
	
	fclose(f2);
	
	Matrix matrix3;
	
	FILE *f3=fopen(argv[3],"r");
	if (f3==NULL){
		printf("cant open file");
		exit(1);	
	}
	
	get_rows(&matrix3,f3);
	get_cols(&matrix3,f3);
	create_matrix(&matrix3,f3);
	
	fclose(f3);

	multiplication(&matrix1,&matrix2,&matrix3);

	//set_elem(&matrix1, 0, 0, 20);
	//int b=get_elem(&matrix1, 0, 0);
	//printf("%d",b);
	
	free_matrix(&matrix1);
	free_matrix(&matrix2);
	free_matrix(&matrix3);

	return 0;
}

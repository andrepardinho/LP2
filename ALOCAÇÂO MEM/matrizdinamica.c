//MAtriz dinamica com alocação de memória

#include <stdio.h>
#include <stdlib.h>



int main ( ) {
    
    int **mat, i, j;

    mat = (int **) malloc(4 * sizeof(int *));

    for (i = 0; i < 4; i++) {
        mat[i] = (int *) malloc(4 * sizeof(int));
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            // mat[i][j] = i + j;
            *(*(mat + i) + j) = i + j;
        }
    } 

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            //printf("%d ", mat[i][j]);
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
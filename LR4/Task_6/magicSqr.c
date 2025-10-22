#include "stdlib.h"
#include <stdio.h>
#include "magicSqr.h"

int** createSquare(int n){
    int **square=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        square[i]=(int *)malloc(sizeof(int)*n);
    }
    return square;
}

void freeSquare(int n, int** square){
    for (int i = 0; i < n; i++)
    {
        free(square[i]);
    }
    free(square);
    
}
int** resultMatrix(int n){
    int **matrix = createSquare(n);

    int i = n / 2;     
    int j = n - 1;

    for (int num = 1; num <= n * n; ) {
        if (i == -1 && j == n) {
            i = 0;
            j = n - 2;
        } else {
            if (i < 0) i = n - 1;
            if (j == n) j = 0;
        }

        if (matrix[i][j] != 0) {
            i += 1;
            j -= 2;
            continue;
        } else {
            matrix[i][j] = num++; 

        i -= 1;
        j += 1;
        }
    }

    return matrix;
    freeSquare(n,matrix);
    
}
void printMatrix(int n, int** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
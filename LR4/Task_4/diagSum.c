#include <stdlib.h>
#include "diagSum.h"

void addValue(int **arr, int *size, int value){
    *arr=(int*)realloc(*arr, (*size+1)*sizeof(int));
    (*arr)[*size]=value;
    (*size)++;
}

int*** create3DArray(int n){
    int*** array=(int***)malloc(n*sizeof(int**));
    for (int i = 0; i < n; i++)
    {
        array[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            array[i][j] = (int*)malloc(n * sizeof(int));
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                scanf("%d", &array[i][j][k]);
            }
        }
    }
    return array;
}

int maxDiagonalSum(int ***arr, int n) {
    int sum1=0, sum2=0, sum3=0, sum4=0;
    for(int i=0;i<n;i++){
        sum1 += arr[i][i][i];
        sum2 += arr[i][i][n-1-i];
        sum3 += arr[i][n-1-i][i];
        sum4 += arr[n-1-i][i][i];
    }
    int max = sum1;
    if(sum2>max) max=sum2;
    if(sum3>max) max=sum3;
    if(sum4>max) max=sum4;
    return max;
}
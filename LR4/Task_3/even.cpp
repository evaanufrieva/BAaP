#include <iostream>
#include "even.h"

int findEvenMainDiagonal(int m, int n, int arr[100][100]){
    int s=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            if (i==j && arr[i][j]%2==0)
            {
                s++;   
            }
        }
    }
    return s;
    
}
int findEvenSideDiagonal(int m, int n, int arr[100][100]){
    int s=0;
    for (int i = 0; i < m; i++)
    {
        int j=n-1-i;
        if (arr[i][j]%2==0)
        {
            s++;
        }
    }
    return s;    
}
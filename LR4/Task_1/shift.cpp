#include "shift.h"

void shiftLeft(int arr[], int k, int n){
    if (k<=0) return;
    for (int i = 0; i < n; i++)
    {
        int temp=arr[0];
        for (int j = 0; j < k; j++)
        {
            arr[j]=arr[j+1];
        }
        arr[k-1]=temp;
    }
    
}
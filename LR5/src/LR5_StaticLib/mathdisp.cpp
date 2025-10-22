#include "mathdisp.h"
#include <iostream>
#include <cmath>

double* setArray(int n){
    double* arr = new double[n];
    //заполнила массив ai элементами в зав-ти от i
    for (int i = 0; i < n; i++)
    {
        int ind=i+1;
        if (i>17) arr[i]=sin(ind); else arr[i]=1.0/tan(ind*ind);
    }
    return arr;
}

double calcMean(double* arr, int n){
    double sum=0.0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    

    return sum/n;
}

double calcVariance(double* arr, int n, double mean){
    double disp=0.0;
    for (int i = 0; i < n; i++)
    {
        disp+=(arr[i] - mean)*(arr[i] - mean);
    }
    
    return disp/n;
}

void deleteArray(double*& arr){
    delete[] arr;
    arr=nullptr;    

}
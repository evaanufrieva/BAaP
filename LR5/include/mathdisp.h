#pragma once
double* setArray(int n);
double calcMean(double* arr, int n);
double calcVariance(double* arr, int n, double mean);

void deleteArray(double*& arr);
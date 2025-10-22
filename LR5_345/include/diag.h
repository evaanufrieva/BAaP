#pragma once

int** setArray(int n, int k);
int* getNumsArray(int** arr, int n, int k, int& outSize);
int prodOfResArray(int* resArray, int size);
void deleteMatrix(int**& arr, int rows);
void deleteArray(int*& arr);
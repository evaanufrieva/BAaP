#include "diag.h"
#include <iostream>
#include <cmath>

int** setArray(int n, int k) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[k]{0};
    }
    return arr;
}

int* getNumsArray(int** arr, int n, int k, int& outSize) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        if (j < k && arr[i][j] % 2 == 0)
            count++;
    }
    outSize = count;
    int* res = new int[count];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        if (j < k && arr[i][j] % 2 == 0)
            res[idx++] = arr[i][j];
    }
    return res;
}

int prodOfResArray(int* resArray, int size) {
    int prod = 1;
    for (int i = 0; i < size; i++)
        prod *= resArray[i];
    return prod;
}

void deleteMatrix(int**& arr, int n) {
    if (!arr) return;
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}
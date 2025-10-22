#include "nullElem.h"
#include <iostream>

double** createIntMatrix(int rows, int cols) {
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols]{0.0};
    }
    return matrix;
}

IndexPair* findZeroes(double** matrix, int n, int k, int& zeroCount) {
    zeroCount = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            if (matrix[i][j] == 0.0)
                zeroCount++;

    if (zeroCount == 0) return nullptr;

    IndexPair* zeroes = new IndexPair[zeroCount];
    int idx = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            if (matrix[i][j] == 0.0)
                zeroes[idx++] = {i, j};
    return zeroes;
}

void reverseMatrix(double **matrix, int n, int k) {
    int total = n * k;
    double *temp = new double[total];
    int idx = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            temp[total - 1 - idx++] = matrix[i][j];

    idx = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            matrix[i][j] = temp[idx++];
    delete[] temp;
}

void printMatrix(double** matrix, int n, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void deleteMatrix(double**& matrix, int rows) {
    if (!matrix) return;
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;
}

void deleteZeroes(IndexPair*& arr) {
    if (!arr) return;
    delete[] arr;
    arr = nullptr;
}
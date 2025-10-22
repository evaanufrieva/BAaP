#pragma once

struct IndexPair {
    int row;
    int col;
};

double** createIntMatrix(int n, int k);
IndexPair* findZeroes(double** matrix, int n, int k, int& zeroCount);
void reverseMatrix(double** matrix, int n, int k);
void printMatrix(double** matrix, int n, int k);
void deleteMatrix(double**& arr, int rows);
void deleteZeroes(IndexPair*& arr);
int validNumber();
void realization();

#pragma once

int** createMatrix(int n, int k);
void printMatrix(int** matrix, int n, int k);
void delMatrix(int**& matrix, int rows);
double computeOddInEvenColumns(int** matrix, int n, int k);

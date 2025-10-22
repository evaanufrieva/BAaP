#include "odd.h"
#include <iostream>

int** createMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols]{0};
    return matrix;
}

void printMatrix(int** matrix, int n, int k)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void delMatrix(int**& matrix, int rows)
{
    if (!matrix) return;
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;
}

double computeOddInEvenColumns(int** matrix, int n, int k)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; j += 2)
        {
            if (matrix[i][j] % 2 != 0)
            {
                sum += matrix[i][j];
                count++;
            }
        }
    }

    if (count == 0) return 0.0;
    return sum / count;
}

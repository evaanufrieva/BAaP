#include <gtest/gtest.h>
#include "../include/odd.h"
#include "../include/nullElem.h"
#include "../include/diag.h"

TEST(Task5Tests, CreateMatrix) {
    int rows = 3;
    int cols = 4;
    int** mat = createMatrix(rows, cols);
    ASSERT_NE(mat, nullptr);

    for (int i = 0; i < rows; ++i) {
        ASSERT_NE(mat[i], nullptr);
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(mat[i][j], 0);
        }
    }
    delMatrix(mat, rows);
    EXPECT_EQ(mat, nullptr);
}

TEST(Task5Tests, BasicCase) {
    int rows = 3, cols = 3;
    int** mat = createMatrix(rows, cols);

    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    double sum = 0.0;
    int count = 0;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j+=2){
            if(mat[i][j] % 2 != 0){
                sum += mat[i][j];
                count++;
            }
        }
    }

    double expected_avg = sum / count;

    ASSERT_DOUBLE_EQ(expected_avg, (1.0 + 3.0+ 7.0 + 9.0)/ 4.0);
    delMatrix(mat, rows);
}

TEST(Task5Tests, SingleRow) {
    int rows = 1, cols = 4;
    int** mat = createMatrix(rows, cols);
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3; mat[0][3] = 4;

    double sum = 0;
    int count = 0;

    for(int j = 0; j < cols; j+=2){
        if(mat[0][j] % 2 != 0){
            sum += mat[0][j];
            count++;
        }
    }

    ASSERT_DOUBLE_EQ(sum / count, (1 + 3) / 2.0);
    delMatrix(mat, rows);
}

TEST(Task5Tests, NoOddNumbers) {
    int rows = 2, cols = 2;
    int** mat = createMatrix(rows, cols);

    mat[0][0] = 2; mat[0][1] = 4;
    mat[1][0] = 6; mat[1][1] = 8;

    double sum = 0;
    int count = 0;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j+=2){
            if(mat[i][j] % 2 != 0){
                sum += mat[i][j];
                count++;
            }
        }
    }

    ASSERT_EQ(count, 0);
    delMatrix(mat, rows);
}


TEST(Task4Tests, BasicCase) {
    int n = 2, k = 3;
    double** mat = createIntMatrix(n, k);
    mat[0][0] = 0.0; mat[0][1] = 2.0; mat[0][2] = 3.0;
    mat[1][0] = 4.0; mat[1][1] = 0.0; mat[1][2] = 6.0;

    int zeroCount;
    IndexPair* zeros = findZeroes(mat, n, k, zeroCount);

    ASSERT_EQ(zeroCount, 2);
    EXPECT_EQ(zeros[0].row, 0);
    EXPECT_EQ(zeros[0].col, 0);
    EXPECT_EQ(zeros[1].row, 1);
    EXPECT_EQ(zeros[1].col, 1);

    deleteZeroes(zeros);
    deleteMatrix(mat, n);
}

TEST(Task4Tests, NoZeroElements) {
    int n = 2, k = 2;
    double** mat = createIntMatrix(n, k);
    mat[0][0] = 1.0; mat[0][1] = 2.0;
    mat[1][0] = 3.0; mat[1][1] = 4.0;

    int zeroCount;
    IndexPair* zeros = findZeroes(mat, n, k, zeroCount);

    EXPECT_EQ(zeroCount, 0);
    EXPECT_EQ(zeros, nullptr);

    deleteMatrix(mat, n);
}

TEST(Task4Tests, SingleElementZero) {
    int n = 1, k = 1;
    double** mat = createIntMatrix(n, k);
    mat[0][0] = 0.0;

    int zeroCount;
    IndexPair* zeros = findZeroes(mat, n, k, zeroCount);

    ASSERT_EQ(zeroCount, 1);
    EXPECT_EQ(zeros[0].row, 0);
    EXPECT_EQ(zeros[0].col, 0);

    deleteZeroes(zeros);
    deleteMatrix(mat, n);
}


TEST(Task3Tests, BasicCase) {
    int n = 3, k = 3;
    int** mat = setArray(n, k);
    mat[0][0] = 2; mat[1][1] = 4; mat[2][2] = 6;

    int size;
    int* res = getNumsArray(mat, n, k, size);
    int prod = prodOfResArray(res, size);

    EXPECT_EQ(size, 3);
    EXPECT_EQ(prod, 2 * 4 * 6);

    deleteArray(res);
    deleteMatrix(mat, n);
}

TEST(Task3Tests, SingleElement) {
    int n = 1, k = 1;
    int** mat = setArray(n, k);
    mat[0][0] = 8;

    int size;
    int* res = getNumsArray(mat, n, k, size);
    int prod = prodOfResArray(res, size);

    EXPECT_EQ(size, 1);
    EXPECT_EQ(prod, 8);

    deleteArray(res);
    deleteMatrix(mat, n);
}

TEST(Task3Tests, NoEvenDiagonal) {
    int n = 2, k = 2;
    int** mat = setArray(n, k);
    mat[0][0] = 1; mat[1][1] = 3;

    int size;
    int* res = getNumsArray(mat, n, k, size);
    int prod = prodOfResArray(res, size);

    EXPECT_EQ(size, 0);
    EXPECT_EQ(prod, 1);

    deleteArray(res);
    deleteMatrix(mat, n);
}

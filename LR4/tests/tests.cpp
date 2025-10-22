#include <gtest/gtest.h>
extern "C" {
#include "diagSum.h"
#include "saper.h"
#include "magicSqr.h"
#include <stdlib.h>
}
#include "../Task_1/shift.h"
#include "../Task_2/saddle.h"
#include "../Task_3/even.h"
#include "../Task_4/diagSum.h"
#include "../Task_5/saper.h"
#include "../Task_6/magicSqr.h"
#include <vector>



TEST(ShiftLeftTest, Basic){
    int arr[5]={1,2,3,4,5};
    shiftLeft(arr, 5,2);
    int expected[5]={3,4,5,1,2};
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(arr[i], expected[i]);
    }
}

TEST(FindEven, MainDiag){
    int arr[100][100] = {
        {2, 1, 3},
        {4, 6, 5},
        {7, 8, 10}
    };    
    EXPECT_EQ(findEvenMainDiagonal(3,3,arr),3);
}

TEST(FindEven, SideDiag){
    int arr[100][100] = {
        {2, 1, 3},
        {4, 6, 5},
        {7, 8, 10}
    };    
    EXPECT_EQ(findEvenSideDiagonal(3,3,arr),1);
}

TEST(FindSaddle, OneNumber){
    int n=3, m=3;
    int** numbers= new int*[n];
    for (int i = 0; i < n; i++)
    {
        numbers[i] = new int[m];
    }
    int init[3][3]={
        {2, 1, 3},
        {4, 6, 5},
        {7, 8, 10}
    };
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){numbers[i][j]=init[i][j];}
    }   
    std::vector<std::pair<int,int>> expected = {{2,0}};
    auto res=findSaddle(n,m, numbers);
    for (size_t i = 0; i < res.size(); i++)
    {
        EXPECT_EQ(res[i].first, expected[i].first);
        EXPECT_EQ(res[i].second, expected[i].second);
    }
    for (int i = 0; i < n; i++)
    {
        delete[] numbers[i];
    }
    delete[] numbers;
    
}

TEST(FindSaddle, TwoNumbers){
    int n=3, m=3;
    int** numbers= new int*[n];
    for (int i = 0; i < n; i++)
    {
        numbers[i] = new int[m];
    }
    int init[3][3]={
        {5, 4, 5},
        {3, 2, 3},
        {5, 4, 5}
    };
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){numbers[i][j]=init[i][j];}
    }   
    std::vector<std::pair<int,int>> expected = {{0,1},{2,1}};
    auto res=findSaddle(n,m, numbers);
    ASSERT_EQ(expected.size(), res.size());

    for (size_t i = 0; i < res.size(); i++)
    {
        EXPECT_EQ(res[i].first, expected[i].first);
        EXPECT_EQ(res[i].second, expected[i].second);
    }
    for (int i = 0; i < n; i++)
    {
        delete[] numbers[i];
    }
    delete[] numbers;   
}

TEST(DiagonalSumTest, SmallCube2x2x2) {
    int n = 2;
    int ***arr = (int ***)malloc(n * sizeof(int **));
    for(int i=0;i<n;i++){
        arr[i] = (int **)malloc(n*sizeof(int*));
        for(int j=0;j<n;j++){
            arr[i][j] = (int*)malloc(n*sizeof(int));
        }
    }

    arr[0][0][0] = 1; arr[0][0][1] = 2;
    arr[0][1][0] = 3; arr[0][1][1] = 4;
    arr[1][0][0] = 5; arr[1][0][1] = 6;
    arr[1][1][0] = 7; arr[1][1][1] = 8;

    EXPECT_EQ(maxDiagonalSum(arr,n), 9);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}

TEST(SaperTest, Basic2x2){
    int n=2;
    char **field=(char**)malloc(sizeof(char*)*n);
    for (int i = 0; i < n; i++){
        field[i]=(char *)malloc(sizeof(char)*n);
    }
    field[0][0]='*';
    field[0][1]='*';
    field[1][0]='.';
    field[1][1]='.';
    char **minesField=inputNumbersField(n,n,field);
    char **expectedField=(char**)malloc(sizeof(char*)*n);
    for (int i = 0; i < n; i++){
        expectedField[i]=(char *)malloc(sizeof(char)*n);
    }
    expectedField[0][0]='*';
    expectedField[0][1]='*';
    expectedField[1][0]='2';
    expectedField[1][1]='2';
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            EXPECT_EQ(minesField[i][j], expectedField[i][j]);        
        }
        
    }
    
    for(int i=0;i<n;i++){
        free(field[i]);
        free(expectedField[i]);
    }
    free(field);
    free(expectedField);
}

TEST(SaperTest, Basic3x4){
    int n = 3;
    int m = 4;

    char **field = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++){
        field[i] = (char*)malloc(sizeof(char) * m);
    }

    field[0][0] = '*'; field[0][1] = '.'; field[0][2] = '.'; field[0][3] = '*';
    field[1][0] = '.'; field[1][1] = '.'; field[1][2] = '.'; field[1][3] = '.';
    field[2][0] = '.'; field[2][1] = '*'; field[2][2] = '.'; field[2][3] = '.';

    char **minesField = inputNumbersField(n, m, field);

    char **expectedField = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++){
        expectedField[i] = (char*)malloc(sizeof(char) * m);
    }

    expectedField[0][0] = '*'; expectedField[0][1] = '1'; expectedField[0][2] = '1'; expectedField[0][3] = '*';
    expectedField[1][0] = '2'; expectedField[1][1] = '2'; expectedField[1][2] = '2'; expectedField[1][3] = '1';
    expectedField[2][0] = '1'; expectedField[2][1] = '*'; expectedField[2][2] = '1'; expectedField[2][3] = '0';

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            EXPECT_EQ(minesField[i][j], expectedField[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        free(field[i]);
        free(expectedField[i]);
    }
    free(field);
    free(expectedField);
}
TEST(MagicSquare, Basic3x3){
    int n = 3;

    int **matrix = resultMatrix(n);
    int expected[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };
    for (int i = 0; i < n; i++){
        for (int j = 0; i < n; j++){
            EXPECT_EQ(matrix[i][j], expected[i][j]);
        }
    }
    freeSquare(n,matrix);

}

TEST(MagicSquare, Basic5x5) {
    int n = 5;

    int **matrix = resultMatrix(n);

    int expected[5][5] = {
        {17, 24,  1,  8, 15},
        {23,  5,  7, 14, 16},
        { 4,  6, 13, 20, 22},
        {10, 12, 19, 21,  3},
        {11, 18, 25,  2,  9}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            EXPECT_EQ(matrix[i][j], expected[i][j]);
        }
    }

    freeSquare(n, matrix);
}

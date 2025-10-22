#include <gtest/gtest.h>
#include "../include/mathdisp.h"
#include "../include/rec.h"

// --------------------------
// Базовый тест
// --------------------------
TEST(MathDispTest, BasicTest) {
    // Arrange
    double arr[] = {1.0, 2.0, 3.0};
    int n = 3;

    // Act
    double mean = calcMean(arr, n);
    double variance = calcVariance(arr, n, mean);

    // Accept
    EXPECT_DOUBLE_EQ(mean, 2.0);
    EXPECT_NEAR(variance, 0.6666667, 1e-6); // допускаем небольшую погрешность
}

// --------------------------
// Краевой тест 1: минимальный размер массива
// --------------------------
TEST(MathDispTest, SingleElementTest) {
    double arr[] = {5.0};
    int n = 1;
    double mean = calcMean(arr, n);
    double variance = calcVariance(arr, n, mean);

    EXPECT_DOUBLE_EQ(mean, 5.0);
    EXPECT_DOUBLE_EQ(variance, 0.0);
}

// --------------------------
// Краевой тест 2: большие значения
// --------------------------
TEST(MathDispTest, LargeValuesTest) {
    double arr[] = {1e9, -1e9};
    int n = 2;
    double mean = calcMean(arr, n);
    double variance = calcVariance(arr, n, mean);

    EXPECT_DOUBLE_EQ(mean, 0.0);
    EXPECT_DOUBLE_EQ(variance, 1e18);
}

TEST(CountNegSinTest, BasicTest) {
    double arr[] = {0.0, 1.0, 2.0, 3.0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countNegSin(arr, 0, n - 1);

    // В массиве sin(x/2) < 0 только для x = 0? (sin(0)=0, не <0), sin(1/2)>0, sin(2/2)=sin(1)>0, sin(3/2)>0
    // Значит count = 0
    EXPECT_EQ(result, 0);
}

// -------------------------
// Краевой тест 1: все отрицательные
// -------------------------
TEST(CountNegSinTest, AllNegative) {
    double arr[] = {-3.14159, -2.0, -1.0, -0.5}; // sin(x/2) < 0 для всех
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countNegSin(arr, 0, n - 1);
    EXPECT_EQ(result, n);
}

// -------------------------
// Краевой тест 2: пустой массив
// -------------------------
TEST(CountNegSinTest, EmptyArray) {
    double arr[] = {};
    int n = 0;

    int result = countNegSin(arr, 0, n - 1);
    EXPECT_EQ(result, 0);
}

// --------------------------
// main для запуска тестов
// --------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

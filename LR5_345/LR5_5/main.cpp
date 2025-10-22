#include <iostream>
#include "odd.h"
#include <vector>

#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"

int validNumber() {
    int n;
    while (true) {
        std::cout << "Введите число n (количество строк матрицы): ";
        std::cin >> n;
        if (std::cin.fail() || n <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: нужно ввести натуральное число!\n";
        } else return n;
    }
}


void realization()
{
    int n = validNumber();
    std::cout << "Введите количество столбцов k: ";
    int k;
    while (true)
    {
        std::cin >> k;
        if (std::cin.fail() || k <= 0)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: нужно ввести натуральное число!\n";
        }
        else break;
    }

    int** arr = createMatrix(n, k);

    std::cout << "Введите элементы матрицы " << n << "x" << k << ":\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
        {
            std::cout << "arr[" << i << "][" << j << "] = ";
            std::cin >> arr[i][j];
        }

    std::cout << "\nВведённая матрица:\n";
    printMatrix(arr, n, k);

    double arithmRes = computeOddInEvenColumns(arr, n, k);
    if (arithmRes == 0.0)
        std::cout << "Нечётных элементов в чётных столбцах нет.\n";
    else
        std::cout << "Среднее арифметическое нечётных элементов матрицы в чётных столбцах: "
                  << arithmRes << "\n";

    delMatrix(arr, n);
}

void help() {
    std::cout << YELLOW
              << "\n=== Контекстное меню ===\n"
              << "Исполнила: Ануфриева Ева\n"
              << "1 - выполнить программу\n"
              << "2 - вывести меню\n"
              << "3 - выход\n"
              << "========================\n"
              << RESET;
}

int main() {
    std::cout << GREEN
              << "Добро пожаловать! Задача: найти все нулевые элементы массива и вывести их индексы и количество, "
              << "также перевернуть матрицу и вывести ее.\n"
              << RESET;

    help();
    std::string cmd;
    while (true) {
        std::cout << GREEN << "~$ " << RESET;
        std::cin >> cmd;
        if (cmd == "1") realization();
        else if (cmd == "2") help();
        else if (cmd == "3") break;
        else std::cout << RED << "[!] Неизвестная команда\n" << RESET;
    }
}

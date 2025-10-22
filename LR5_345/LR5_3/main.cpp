#include <iostream>
#include "diag.h"
#include <vector>
#include <climits>

#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"

int validNumber()
{
     while (true)
    {
        std::cout << "Введите число: ";

        std::string input;
        std::getline(std::cin, input);

        while (!input.empty() && std::isspace(input.front())) input.erase(input.begin());
        while (!input.empty() && std::isspace(input.back())) input.pop_back();

        if (input.empty()) {
            std::cout << "Ошибка: пустой ввод!\n";
            continue;
        }

        bool valid = true;
        for (char c : input) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            std::cout << "Ошибка: ввод должен содержать только натуральное число!\n";
            continue;
        }

        long long value = std::stoll(input);
        if (value <= 0) {
            std::cout << "Ошибка: число должно быть больше 0!\n";
            continue;
        }

        if (value > INT_MAX) {
            std::cout << "Ошибка: число слишком большое!\n";
            continue;
        }

        return static_cast<int>(value);
    }
}

void realization() {

    std::cout << "Введите количество строк n: ";
    int n = validNumber();

    std::cout << "Введите количество столбцов k: ";
    int k = validNumber();

    int** arr = setArray(n, k);
    std::cout << "Введите элементы матрицы " << n << "x" << k << ":\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << "arr[" << i << "][" << j << "] = ";
            std::cin >> arr[i][j];
        }
    }

    std::cout << "\nВведённая матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    int size;
    int* resNumArray = getNumsArray(arr, n, k, size);
    int prod = prodOfResArray(resNumArray, size);
    std::cout << "Результат произведения: " << prod << "\n";

    deleteArray(resNumArray);
    deleteMatrix(arr, n);
    std::cin.ignore(1000, '\n');

}


void help() {
    std::cout << YELLOW
              << "\n=== Контекстное меню ===\n"
              << "Исполнила: Ануфриева Ева\n"
              << "1 - выполнить расчёт\n"
              << "2 - вывести меню\n"
              << "3 - выход\n"
              << "========================\n"
              << RESET;
}

int main() {
    std::cout << GREEN
              << "Добро пожаловать! Задача: создать динамический массив из четных чисел, расположенных "
              << "на главной диагонали, и вычислить их произведение.\n"
              << RESET;

    help();
    std::string cmd;
    while (true) {
        std::cout << GREEN << "~$ " << RESET;
        std::string cmd;
        std::getline(std::cin, cmd);

        // убираем пробелы
        while (!cmd.empty() && std::isspace(cmd.front())) cmd.erase(cmd.begin());
        while (!cmd.empty() && std::isspace(cmd.back())) cmd.pop_back();

        if (cmd == "1") realization();
        else if (cmd == "2") help();
        else if (cmd == "3") break;
        else std::cout << RED << "[!] Неизвестная команда\n" << RESET;
    }
}

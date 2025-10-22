#include <iostream>
#include "rec.h"
#include <cmath>
#include <climits>
#include <string>
#include <cctype>

#ifdef _WIN32
    #define IMPORT extern "C" __declspec(dllimport)
#else
    #define IMPORT extern "C"
#endif

IMPORT int STDCALL countNegSin(double* arr, int left, int right);

#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"

int validNumber()
{
     while (true)
    {
        std::cout << "Введите число n (размерность массива): ";

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

void realization()
{
    int n = validNumber();
    double* arr = new double[n];
    std::cout << "Введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "x[" << i + 1 << "] = ";
        std::cin >> arr[i];
    }

    int count = countNegSin(arr, 0, n - 1);
    std::cout << "\nКоличество элементов, для которых sin(x/2) < 0: " << count << std::endl;

    delete[] arr;
    std::cin.ignore(1000, '\n');

}

void help()
{
    std::cout << YELLOW
              << "\n=== Контекстное меню ===\n"
              << "Исполнила: Ануфриева Ева\n"
              << "1 - выполнить расчёт\n"
              << "2 - вывести меню\n"
              << "3 - выход\n"
              << "========================\n"
              << RESET;
}

int main()
{
    std::cout << GREEN
              << "Добро пожаловать! Задача: рекурсивно посчитать элементы массива, "
              << "для которых sin(x/2) < 0.\n"
              << RESET;

    help();
    std::string cmd;
    
    while (true)
    {
        std::cout << GREEN << "~$ " << RESET;
        std::string command;
        std::getline(std::cin, cmd); // читаем всю строку команды

        // Удаляем пробелы по краям
        while (!cmd.empty() && std::isspace(cmd.front())) cmd.erase(cmd.begin());
        while (!cmd.empty() && std::isspace(cmd.back())) cmd.pop_back();
        if (cmd == "1") realization();
        else if (cmd == "2") help();
        else if (cmd == "3") break;
        else std::cout << RED << "[!] Неизвестная команда\n" << RESET;
    }
}

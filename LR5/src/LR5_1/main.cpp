#include <iostream>
#include "mathdisp.h"
#include <climits>
#include <string>
#include <cctype>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

// Функция для проверки ввода натурального числа
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
    double *arr = setArray(n);
    double mean = calcMean(arr, n);
    double variance = calcVariance(arr, n, mean);

    std::cout << "Элементы массива:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nЗначение математического ожидания: " << mean << "\n";
    std::cout << "Значение математической дисперсии: " << variance << "\n";

    delete[] arr;
}

void help()
{
    std::cout << YELLOW
              << "\n=== Контекстное меню ===\n"
              << "Исполнила: Ануфриева Ева\n"
              << "Доступные команды:\n"
              << "   1   - выполнить расчёт\n"
              << "   2   - вывести это меню\n"
              << "   3   - завершить программу\n"
              << "========================\n"
              << RESET;
}

int main()
{
    std::cout << GREEN
              << "\nДобро пожаловать в лабораторную работу 5 Задание 1!\n"
              << "В данной программе реализовано вычисление математического ожидания m и дисперсии D\n"
              << RESET;

    help();

    while (true)
    {
        std::cout << GREEN << "~$ " << RESET;
        std::string command;
        std::getline(std::cin, command); // читаем всю строку команды

        // Удаляем пробелы по краям
        while (!command.empty() && std::isspace(command.front())) command.erase(command.begin());
        while (!command.empty() && std::isspace(command.back())) command.pop_back();

        if (command == "1")
        {
            realization();
        }
        else if (command == "2")
        {
            help();
        }
        else if (command == "3")
        {
            break;
        }
        else
        {
            std::cout << RED << "[!] Команда \"" << command
                      << "\" не найдена. Введите 2 для справки.\n"
                      << RESET;
        }
    }

    std::cout << GREEN << "\n[*] Программа завершена.\n" << RESET;
    return 0;
}

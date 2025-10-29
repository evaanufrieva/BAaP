#include "inplace.h"

#include <iostream>

InPlace::InPlace() : input(nullptr), lenArray(0) {};
InPlace::~InPlace()
{
    delete[] input;
}

bool InPlace::readInput()
{
    char buffer[201];

    do
    {
        std::cout << "Введите текст: ";
        std::cin.getline(buffer, 201);

        lenArray = 0;
        while (buffer[lenArray] != '\0')
        {
            lenArray++;
        }

        if (lenArray == 0)
        {
            std::cout << "Ошибка: строка не может быть пустой!\n";
        }

    } while (lenArray == 0);

    delete[] input;
    input = new char[lenArray + 1];

    for (size_t i = 0; i < lenArray; i++)
    {
        input[i] = buffer[i];
    }
    input[lenArray] = '\0';

    return true;
}

void InPlace::inplaceWords()
{
    int start = 0;
    int end = lenArray - 1;
    while (start < end)
    {
        char tmp = input[start];
        input[start] = input[end];
        input[end] = tmp;
        start++;
        end--;
    }
    int wordStart = 0;
    for (int i = 0; i <= lenArray; i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            int left = wordStart;
            int right = i - 1;
            while (left < right)
            {
                char tmp = input[left];
                input[left] = input[right];
                input[right] = tmp;
                left++;
                right--;
            }
            wordStart=i+1;
        }
    }
}
void InPlace::printNewStr() const
{
    for (int i = 0; i < lenArray; i++)
    {
        std::cout << input[i];
    }
    std::cout << "\n";
}
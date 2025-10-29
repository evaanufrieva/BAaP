#include "substr.h"
#include <cstddef>
#include <cstring>
#include <iostream>

SubStr::SubStr() : input(nullptr), substr(nullptr), symbol('\0'), textLength(0), substringLength(0) {};
SubStr::~SubStr()
{
    delete[] input;
    delete[] substr;
}

bool SubStr::readInput()
{
    char buffer[201];
    do
    {
        std::cout << "Введите текст ";
        std::cin.getline(buffer, sizeof(buffer));
        textLength = strlen(buffer);
        if (textLength == 0)
        {
            std::cout << "Ошибка: строка не может быть пустой!\n";
        }
    } while (textLength == 0);

    delete[] input;
    input = new char[textLength + 1];
    for (size_t i = 0; i <= textLength; ++i)
    {
        input[i] = buffer[i];
    }

    std::string line;
    do
    {
        std::cout << "Введите символ, после которого вставить подстроку: ";
        std::getline(std::cin, line);
        if (line.empty())
        {
            std::cout << "Ошибка: символ не может быть пустым!\n";
        }
    } while (line.empty());
    symbol = line[0];

    do
    {
        std::cout << "Введите подстроку (до 100 символов): ";
        std::cin.getline(buffer, 101);
        substringLength = strlen(buffer);

        if (substringLength == 0)
        {
            std::cout << "Ошибка: подстрока не может быть пустой!\n";
        }
    } while (substringLength == 0);

    delete[] substr;
    substr = new char[substringLength + 1];
    for (size_t i = 0; i <= substringLength; ++i)
    {
        substr[i] = buffer[i];
    }

    return true;
}


void SubStr::placeSubStr()
{
    if (!input || !substr || textLength == 0 || substringLength == 0)
        return;

    int pos = -1;
    for (int i = 0; i < textLength; i++)
    {
        if (input[i] == symbol)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        std::cout << "Символ '" << symbol << "' не найден.\n";
        return;
    }

    size_t newLen = textLength + substringLength;
    char* newText = new char[newLen + 1];

    for (int i = 0; i <= pos; ++i)
    {
        newText[i] = input[i];
    }

    for (int i = 0; i < substringLength; ++i)
    {
        newText[pos + 1 + i] = substr[i];
    }

    for (int i = pos + 1; i < textLength; ++i)
    {
        newText[substringLength + i] = input[i];
    }

    newText[newLen] = '\0';

    delete[] input;
    input = newText;
    textLength = newLen;
}

void SubStr::printNewStr() const
{
    if (input)
    {
        std::cout << "Результат: " << input << "\n";
    }
}
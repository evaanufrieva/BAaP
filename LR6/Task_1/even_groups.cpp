#include "even_groups.h"
#include <iostream>
#include <cctype>

BinaryGroups::BinaryGroups() : input(nullptr), length(0), groups(nullptr), count(0) {};
BinaryGroups::~BinaryGroups()
{
    delete[] input;
    if (groups)
    {
        for (int i = 0; i < count; i++)
        {
            delete[] groups[i];
        }
        delete[] groups;
    }
}
bool BinaryGroups::setInput(const char* str) {
    delete[] input;
    length = 0;

    while (str[length] != '\0' && length < 80) {
        if (str[length] != '0' && str[length] != '1') {
            input = nullptr;
            length = 0;
            count = 0;
            groups = nullptr;
            return false; 
        }
        length++;
    }

    input = new char[length + 1];
    for (size_t i = 0; i < length; ++i)
        input[i] = str[i];
    input[length] = '\0';

    return true;
}


bool BinaryGroups::readInput()
{
    delete[] input;
    input = new char[81];
    length = 0;

    while (true) {
        std::cout << "Введите строку из 0 и 1 (до 80 символов): ";
        std::string line;
        std::getline(std::cin, line);

        length = 0;
        bool valid = true;

        for (char ch : line) {
            if (ch == '0' || ch == '1') {
                if (length < 80)
                    input[length++] = ch;
            } else if (!isspace(static_cast<unsigned char>(ch))) {
                std::cout << "Недопустимые символы\n";
                valid = false;
                break;
            }
        }

        if (valid && length > 0) {
            input[length] = '\0';
            return true;
        }
    }
}


void BinaryGroups::findEvenGroups()
{
    if (groups) {
        for (int i = 0; i < count; i++)
            delete[] groups[i];
        delete[] groups;
    }
    int start = 0;
    groups = new char *[length];
    while (start < length)
    {
        int end = start;
        while (end < length && input[end] == input[start])
        {
            end++;
        }
        int grouplen = end - start;
        if (grouplen % 2 == 0)
        {
            groups[count] = new char[grouplen + 1];
            for (int i = 0; i < grouplen; i++)
            {
                groups[count][i] = input[start + i];
            }
            groups[count][grouplen] = '\0';
            count++;
        }
        start = end;
    }
}
void BinaryGroups::printGroups() const
{
    if (count == 0)
    {
        std::cout << "Нет групп с чётным количеством символов.\n";
    }
    std::cout << "Группы с чётным количеством символов:\n";
    for (int i = 0; i < count; i++)
        std::cout << groups[i] << '\n';
}
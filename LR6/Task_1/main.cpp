#include <iostream>
#include "even_groups.h"


#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"

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
    BinaryGroups bg;
    std::cout << GREEN
              << "Добро пожаловать! Задача: в строке, состоящей из групп нулей и единиц, найти и вывести на \n экран группы с четным количеством символов"
              << RESET;

    help();
    std::string cmd;
    while (true) {
        std::cout << GREEN << "~$ " << RESET;
        std::string cmd;
        std::getline(std::cin, cmd);

        while (!cmd.empty() && std::isspace(cmd.front())) cmd.erase(cmd.begin());
        while (!cmd.empty() && std::isspace(cmd.back())) cmd.pop_back();

        if (cmd == "1") {
            bg.readInput();
            bg.findEvenGroups();
            bg.printGroups();
        }
        else if (cmd == "2") help();
        else if (cmd == "3") break;
        else std::cout << RED << "[!] Неизвестная команда\n" << RESET;
    }
}

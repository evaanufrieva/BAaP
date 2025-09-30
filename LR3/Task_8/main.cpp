#include <iostream>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void calculate(){
    int n;
    std::cout << YELLOW << "Введите n: " << RESET;
    std::cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cout << "Введите a" << i << ": ";
        std::cin >> a;
        long long term = (1LL << i);
        if (i % 2 == 1) {
            term = -term;
        }

        sum += term * a;
    }
    std::cout << GREEN << "Результат: " << sum << RESET << std::endl;
}


void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Вычислить a0-2a1+4a2-8a3+...+2^n-1*(-1)^n-1*an-1"
            <<"Исполнила: Ануфриева Ева\n"
            <<"Доступные команды:\n"
            << "   calc   - выполнить расчёт\n"
            << "   help   - вывести это меню\n"
            << "   exit   - завершить программу\n"
            << "========================\n" ;
    std::cout<<RESET;
}
int main(){
    std::cout<<GREEN
        <<"\nДобро пожаловать в лабораторную работу 3 Задание 8!\n"
        << "В данной программе реализован расчёт по заданной формуле.\n"
        << RESET;
    help();
    while (true)
    {
       std::string command;
       std::cout << GREEN << "~$ " << RESET;
       std::cin>>command;
       if (command=="calc")
       {
            calculate();
       }else if (command=="help")
       {
            help();
       }else if (command=="exit" || command=="quit")
       {
            break;
       }else{
            std::cout<<RED<< "[!] Команда \"" << command 
                      << "\" не найдена. Введите help для справки.\n" << RESET;
       }

    }
    std::cout << GREEN << "\n[*] Программа завершена.\n" << RESET;
    return 0;
}
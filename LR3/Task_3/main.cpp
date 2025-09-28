#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"


void calculate(){
    int M=20;
    int A=0;
    double B=M_PI/2;
    double H=(B-A)/M;
    for (double i = A; A+i*H <= B; i++)
    {
        double x= A+i*H;
        double y=sin(x)-cos(x);
        std::cout<<GREEN<<"Значение при x= "<<x<<": "<<y<<RESET<<"\n";
    }
    std::cout<<YELLOW<<"Подсчет завершен"<<RESET<<"\n";
}

void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Используя цикл for составить программу вычисления значений функции y = sin(x) - cos(x) на отрезке [A, B] в точках 𝑋𝑖 = 𝐴 + 𝑖 ∗ 𝐻, где H = (B - A) / M, M = 20, A = 0, B = π / 2."
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
        <<"\nДобро пожаловать в лабораторную работу №2 Задание 3!\n"
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


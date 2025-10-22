#include <iostream>
#include "shift.h"

#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void realization(){
    int k,n;
    std::cout<<"Введите число элементов в массиве: ";
    std::cin>>k;
    std::cout<<"Введите, на сколько элементов в массиве его сдвинуть влево: ";
    std::cin>>n;
    int arr[k];
    for (int i = 0; i < k; i++)
    {
        int el;
        std::cout<<"Введите элемент: ";
        std::cin>>arr[i];
    }
    std::cout<<"Массив до сдвига:"<<std::endl;
    for (int i = 0; i < k; i++)
    {
        std::cout<<"Элемент "<<arr[i]<<" под индексом "<<i<<std::endl;
    }
    std::cout<<"Массив после сдвига:"<<std::endl;
    shiftLeft(arr,k,n);
    for (int i = 0; i < k; i++)
    {
        std::cout<<"Элемент "<<arr[i]<<" под индексом "<<i<<std::endl;
    }
}

void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Используя знания о массивах реализовать алгоритм сдвига элементов массива размера k на n позиций  влево\n"
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
        <<"\nДобро пожаловать в лабораторную работу 4 Задание 1!\n"
        << "В данной программе реализован сдвиг элементов массива на n позиций влево\n"
        << RESET;
    help();
    while (true)
    {
       std::string command;
       std::cout << GREEN << "~$ " << RESET;
       std::cin>>command;
       if (command=="calc")
       {
            realization();
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


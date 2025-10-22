#include <iostream>
#include "even.h"

#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void realization() {
    int m, n;
    std::cout << "Введите количество строк в матрице: ";
    std::cin >> m;
    std::cout << "Введите количество столбцов в матрице: ";
    std::cin >> n;
    if (n==m){
        int arr[100][100];
        for (int i = 0; i < m; i++) {
            std::cout << "Введите элементы " << i + 1 << " строки" << std::endl;
            for (int j = 0; j < n; j++) {
                int el;
                std::cout << "Элемент " << j + 1 << ": ";
                std::cin >> el;
                arr[i][j] = el;
            }
        }
        std::cout << "Матрица:" << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            std::cout<<arr[i][j]<<" ";
            }
            std::cout << std::endl;

        }
        int mainCount = findEvenMainDiagonal(m, n, arr);
        int sideCount = findEvenSideDiagonal(m, n, arr);


        std::cout << "Количество чётных элементов на главной диагонали: " << mainCount << std::endl;
        std::cout << "Количество чётных элементов на побочной диагонали: " << sideCount << std::endl;

    }else{
        std::cout<<"Количество строк и столбцов должно совпадать";
    }
}


void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Найти количество четных элементов главной и побочной диагоналей массива\n"
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
        <<"\nДобро пожаловать в лабораторную работу 4 Задание 2!\n"
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


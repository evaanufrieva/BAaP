#include <iostream>
#include "saddle.h"

#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void realization() {
    int m, n;
    std::cout << "Введите количество строк в матрице: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов в матрице: ";
    std::cin >> m;

    int** arr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[m];
    }
     std::cout << "Матрица:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << "Введите элементы " << i + 1 << " строки" << std::endl;
        for (int j = 0; j < m; j++) {
            std::cout << "Элемент " << j + 1 << ": ";
            std::cin >> arr[i][j];
        }
    }
    auto saddles=findSaddle(n,m,arr);
    for (auto [row, col]: saddles)
    {
        std::cout<<"Индекс седловой точки: ("<<row<<"; "<<col<<")\n";
    }
    
}


void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Найти все возможные седловые точки в матрице N*M\n"
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
        <<"\nДобро пожаловать в лабораторную работу 4 Задание 3!\n"
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


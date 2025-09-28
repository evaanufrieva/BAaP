#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"


void calculate(){

    double e=pow(10,-3);
    double sum =0.0;
    double dn;
    double n=1;
    do{
        dn=1.0/pow(2.0,n)+1.0/pow(3.0,n);
        sum+=dn;
        n++;
    } while (dn>=e);
    std::cout<<GREEN<<"Сумма ряда: "<<sum<<RESET<<"\n";

}
void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача:Используя цикл do while найти сумму ряда с точностью 𝜀 = 10−3, общий член которого 𝑑𝑛 = 12𝑛+ 13𝑛. При составлении программы считать, что точность достигнута\n"
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
        <<"\nДобро пожаловать в лабораторную работу!\n"
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


#include <iostream>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"


void calculate(){
    std::vector<int> nums;
    std::vector<int> sum;
    int num,snums;
    std::cout<<YELLOW<<"Введите число: "<<RESET;
    std::cin>>num;
    for (int i =1; i < num; i++)
    {
        int temp=i;
        if (temp>=1 && temp<=9)
        {
            int armstrongNum=temp*temp*temp;
            nums.push_back(armstrongNum);
            sum.push_back(armstrongNum);

        }else{
            while (temp>0)
            {
                int digit=temp%10;
                temp/=10;
                int armstrongNumGreater9=digit*digit*digit;
                snums+=armstrongNumGreater9;
            }
            sum.push_back(snums);
        }   
    }
    std::cout<<GREEN<<"Числа Армстронга, меньше "<<num<<":\n"<<RESET;
    for (int d:sum )
    {
        std::cout<<d<<" ";
    }
    std::cout<<std::endl;
}


void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Вывести все числа Армстронга, меньше введённого пользователем числа. "
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
        <<"\nДобро пожаловать в лабораторную работу 3 Задание 7!\n"
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
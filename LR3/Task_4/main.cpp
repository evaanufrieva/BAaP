#include <iostream>
#include <cmath>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"


void calculate(){
    int n;
    int cnt;
    std::cout<<YELLOW<<"Введите N: количество членов ряда"<<RESET<<"\n";
    std::cin>>n;
    std::cout<<YELLOW<<"Введите количество чисел, от которых нужно посчитать функцию"<<RESET<<"\n";
    std::cin>>cnt;
     
    for (int i = 0; i <cnt; i++){
        double x;
        std::cout<<"Введите число x от 0.1 до 1: ";
        std::cin>>x;
        double S=0.0;
        if (x >= 0.1 && x <= 1.0){
            for (int j = 0; j < n; j++)
            {
               double term=pow(x, 2*j+1)/tgamma(2*j+1);
               S+=term;
            }
            double y=(exp(x)-exp(-x))/2;
            std::cout<<"Сумма ряда Y(x): "<<S<<"\n";
            std::cout<<"Сумма ряда S(x): "<<y<<"\n";
        }else {
            std::cout<<"Введите корректное число x"<<"\n" ;
            i--;
        };
    }      
}

void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Необходимо разложить функцию "<<GREEN<<"(e^x-e^-x)/2 "<<RESET<<YELLOW<<"в ряд "<<GREEN<<"x+x^3/3!+...+(x^2n+1)/(2n+1)!"<<RESET<<YELLOW<<",затем с помощью полученного ряда найти значение функции и сравнить его со значением, вычисленным с помощью стандартных функций."
            <<"Программа запросит у вас количество членов ряда (n), затем количество чисел, от которых он хочет посчитать функцию, затем вы вводите по одному числу (x от 0.1, до 1), программа считает значение функции с помощью ряда и с помощью стандартных функций и выводит оба значения. Постройте блок-схему алгоритма.\n"
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
        <<"\nДобро пожаловать в лабораторную работу №2 Задание 4    !\n"
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


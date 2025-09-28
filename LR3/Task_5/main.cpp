#include <iostream>
#include <cmath>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

double fun(double x){
    return acos(exp(-x)) - 2 * sin(x);
}
void calculate(){
    int n;
    std::cout << YELLOW << "Введите количество частей для интервала [1,3]: " << RESET;
    std::cin >> n;
    if (n <= 0) {
        std::cout << RED << "[!] Ошибка: количество частей должно быть положительным\n" << RESET;
        return;
    }
    
    double a = 1.0, b = 3.0;
    double h = (b - a) / n;
    double minAbsF = std::fabs(fun(a));
    double root = a;

    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double fx = fun(x);
        if (std::fabs(fx) < minAbsF) {
            minAbsF = fabs(fx);
            root = x;
        }
    }
    std::cout << GREEN << "\n[*] Приближенный корень: x = " << root
              << "\n[*] Значение функции f(x) = " << fun(root) << RESET << "\n";
}


void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Необходимо приближенно найти корень уравнения f(x) = 0 для функции из своего варианта. Корень нужно найти по следующему алгоритму: перебираем значения от начала до конца интервала с некоторым шагом и ищем значение функции, минимальное по модулю. Аргумент, при котором оно достигается, считаем корнем уравнения. Программа должна запросить у пользователя, на сколько частей разделить область поиска корня, вычислить шаг, с которым нужно проходить значения, пройти в цикле нужные значения, найти корень и вывести его"
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
        <<"\nДобро пожаловать в лабораторную работу №2 Задание 5 Вариант 6!\n"
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
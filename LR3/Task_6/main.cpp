#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

const double PI = 3.141592653589793;

double myFabs(double x){
    return x<0? -x: x;
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

// приближённое вычисление синуса через ряд Тейлора
double mySin(double x, double eps = 1e-6) {
    // нормализация угла (x в пределах [-2π, 2π])
    while (x > 2 * PI) x -= 2 * PI;
    while (x < -2 * PI) x += 2 * PI;

    double term = x;   // первый член ряда
    double sum = x;
    int n = 1;

    while (myFabs(term) > eps) {
        term = -term * x * x / ((2 * n) * (2 * n + 1)); // формула для следующего члена
        sum += term;
        n++;
    }
    return sum;
}

double normalize(double x) {
    while (x > 2*PI) x -= 2*PI;
    while (x < -2*PI) x += 2*PI;
    return x;
}

double myCos(double x, double eps = 1e-6) {
    x = normalize(x);

    double term = 1.0;   // первый член ряда (1)
    double sum = 1.0;
    int n = 1;

    while (myFabs(term) > eps) {
        // формула для следующего члена
        term = -term * x * x / ((2*n-1) * (2*n));
        sum += term;
        n++;
    }
    return sum;
}

double myLn(double x, double eps = 1e-6) {
    if (x <= 0) {
        std::cout << RED<<"[!] Ошибка: ln(x) определён только для x > 0\n"<<RESET;
        // return 1; СПРОСИТЬ ПО ПОВОДУ КАК УБРАТЬ
    }


    // подстановка: ln(x) = 2 * (y + y^3/3 + y^5/5 + ...), y = (x-1)/(x+1)
    double y = (x - 1) / (x + 1);
    double term = y;   // первый член ряда
    double sum = y;
    int n = 1;

    while (myFabs(term) > eps) {
        term = term * y * y; // повышаем степень: y^(2n+1)
        sum += term / (2 * n + 1);
        n++;
    }

    return 2 * sum;
}

void calculate(){
    double x;
    std::cout<<YELLOW<<"Введите x: "<< RESET;
    std::cin>>x;
    std::cout<<GREEN<<"Значение sin(x): "<<mySin(x)<<RESET<<"\n";
    std::cout<<GREEN<<"Значение cos(x): "<<myCos(x)<<RESET<<"\n";
    std::cout<<GREEN<<"Значение ln(x): "<<myLn(x)<<RESET<<"\n";
}


void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при заданном х,\n определить и вывести на экран дисплея минимальное значение. "
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
        <<"\nДобро пожаловать в лабораторную работу №2 Задание 6!\n"
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
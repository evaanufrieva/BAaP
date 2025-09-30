#include <iostream>

#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"


void calculate(){

    int i=1;
    double sum {};
    std::cout<<YELLOW<<"Вычислим 𝑁 = ∑ (𝑎𝑖 − 𝑏𝑖)^2"<<RESET<<"\n";
    while (i<30)
    {
        double a = i%2? i/2.0 : i;
        double b= i%2? i*i*i:i*i;
        sum+=(a-b)*(a-b);
        i++;
    }
    std::cout<<GREEN<<"Результат вычислений: "<<sum<<RESET<<"\n\n";  

}
void help(){
    std::cout<<YELLOW
            <<"\n=== Контекстное меню ===\n"
            <<"Задача: вычислить сумму N = Σ (aᵢ - bᵢ)² при i=1..n\n"
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
        <<"\nДобро пожаловать в лабораторную работу 3 Задание 1!\n"
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


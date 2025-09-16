#include <iostream>
#include <cmath>

int main(){
    double x,D;
    std::cout<<"Enter x: ";
    std::cin>>x;
    std::cout<<"Enter D: ";
    std::cin>>D;
    double b=x+D;
    double A=D*x/b;
    if (b==0)
    {
        std::cout<<"Can not divide by 0"<<"\n";   
    }else{
        double S=(pow(A, 2)+ b*cos(x))/(pow(D,3)+(A+D-b));
        std::cout<<"S: "<<S<<"\n";
    }
}
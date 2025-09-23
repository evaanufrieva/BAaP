#include <iostream>
#include <cmath>

int main(){
    int choice;
    double a,b,z,x,y;
    std::cout<<"Enter (a b z): ";
    std::cin>> a >> b >> z;
    if (z<0)
    {
        x=z;
    }else
    {
        x=sin(z);
    }
    
    
    std::cout<<"Choose a function:\n1)f(x)=2*x\n2)f(x)=x^3\n3)f(x)=x/3"<<"\n";
    std::cin>>choice;
    if (choice!=1 && choice!=2 && choice!=3)
    {
        std::cout<<"Entered invalid number of function";
    }else{
        switch (choice)
        {
        case 1:
            y=(2.0/3.0)*a*pow(sin(x),2)+pow(sin(pow(x,3)),2)-b*2*x;
            std::cout<<y;
            break;
        case 2:
            y=(2.0/3.0)*a*pow(sin(x),2)+pow(sin(pow(x,3)),2)-b*pow(x,3);
            std::cout<<y;
            break;
        case 3:
            y=(2.0/3.0)*a*pow(sin(x),2)+pow(sin(pow(x,3)),2)-b*x/3;
            std::cout<<y;
            break;
        default:
            break;
        }
    }
    return 0;
    
}
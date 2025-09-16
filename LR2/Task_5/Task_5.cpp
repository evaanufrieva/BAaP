#include <iostream>

int main(){
    float a,b;
    std::cout<<"Enter a:";
    std::cin>>a;
    std::cout<<"Enter b:";
    std::cin>>b;
    if (a>b)
    {
        std::cout<<"a > b"<<"\n";
    }else if (a==b)
    {
        std::cout<<"a == b"<<"\n";
    }else{
        std::cout<<"b > a"<<"\n";
    }   
}
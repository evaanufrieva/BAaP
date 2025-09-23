#include <iostream>

int main(){
    float a,b;
    std::cout<<"Enter a:";
    std::cin>>a;
    std::cout<<"Enter b:";
    std::cin>>b;
    float max=(a>b) ? a:b;
    std::cout<<"Bigger num is "<<max<<"\n";
    return 0;
}
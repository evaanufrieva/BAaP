#include <iostream>
int main(){
    double a,b,c,Y;
    int N;
    std::cout<<"Enter a:";
    std::cin>>a;
    std::cout<<"Enter b:";
    std::cin>>b;
    std::cout<<"Enter c:";
    std::cin>>c;
    std::cout<<"Enter N:";
    std::cin>>N;
    switch (N)
    {
    case 2:
        Y=b*c-a*a;
        std::cout<<Y;
        break;
    case 56:
        Y=b*c;
        std::cout<<Y;
        break;
    case 7:
        Y=a*a+c;
        std::cout<<Y;
        break;
    case 3:
        Y=a-b*c;
        std::cout<<Y;
        break;
    default:
        Y=(a+b)*(a+b)*(a+b);
        std::cout<<Y;
        break;
    }

}
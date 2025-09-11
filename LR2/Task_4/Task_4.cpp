#include <iostream>
int main(){
    int x,y;
    float a,b,c,k;
    std::cout<< "Enter x value: ";
    std::cin>>x;
    std::cout<< "Enter y value: ";
    std::cin>>y;
    std::cout<< "Enter a value: ";
    std::cin>>a;
    std::cout<< "Enter b value: ";
    std::cin>>b;
    std::cout<< "Enter c value: ";
    std::cin>>c;
    std::cout<< "Enter k value: ";
    std::cin>>k;
    if (x<y)
    {
        x=0;
    }else if (x>y)
    {
        y=0;
    }else{
        x,y=0,0;
    }
    if (a>b && a>c)
    {
        a-=k;
    }else if (b>a && b>c)
    {
        b-=k;
    }else if (c>a && c>b)
    {
        c-=k;
    }
    std::cout<<"X: "<<x<<"\n"<<"Y: "<<y<<"\n"<<"A: "<<a<<"\n"<<"b: "<<b<<"\n"<<"C: "<<c<<"\n";
    return 0;
    
}
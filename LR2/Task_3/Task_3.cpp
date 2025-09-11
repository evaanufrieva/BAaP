#include <iostream>

int main(){
    float b1;
    int n=6;
    std::cout<<"Enter b1 from geometry progression: ";
    std::cin>>b1;
    float q=1.0/(n+1);
    float s=b1/(1-q);
    std::cout<<"Sum of infinitely reducing progression: "<<s<<std::endl;
    return 0;

}
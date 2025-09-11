#include <iostream>

int main(){
    double x, ans1, ans2;
    std::cout<< "Enter x number:";
    std::cin>>x;
    ans1=23*x*x*x+69*x*x+32*x+8;
    ans2=-23*x*x*x+69*x*x-32*x+8;
    std::cout << "23х^3 + 69x^2 + 32x + 8 answer: "<<ans1<<"\n";
    std::cout << "-23х^3 + 69x^2 - 32x + 8 answer: "<<ans2;
    return 0;
}
#include <iostream>
int main(){ 
    float x,y,z;
    std::cout << "Enter x value: ";
    std::cin >> x;
    std::cout << "Enter y value: ";
    std::cin >> y;
    std::cout << "Enter z value: ";
    std::cin >> z;

    if (x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x)
    {
        std::cout << "YES Triangle";
    } else {
        std::cout << "NO Triangle";
    }
    return 0;
}

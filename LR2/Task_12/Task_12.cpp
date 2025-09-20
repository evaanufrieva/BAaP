#include <iostream>
#include <cmath>

int main() {
    int choice;
    std::cout << "Select equation type:\n";
    std::cout << "1. ax^4 + bx^2 + c = 0\n";
    std::cout << "2. ax^4 + bx^3 + cx^2 + bx + a = 0\n";
    std::cout << "3. x^3 + px + q = 0\n";
    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << "Switch to branch eq1 to see the solution\n";
            break;
        case 2:
            std::cout << "Switch to branch eq2 to see the solution\n";
            break;
        case 3:
            std::cout << "Switch to branch eq3 to see the solution\n";
            break;
        default:
            std::cout << "Invalid choice\n";
    }

    return 0;
}

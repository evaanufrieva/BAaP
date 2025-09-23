#include <iostream>
using namespace std;
int main() {
    double x;
    cout << "x: ";
    cin >> x;

    double x2 = x * x;     
    double v1 = x * (23 * x + 32);   
    double v2 = 69 * x2 + 8;  

    double f1 = v1 * x + v2;        
    double f2 = v2 - v1 * x;

    cout << f1 << endl << f2 << endl;
    return 0;
}
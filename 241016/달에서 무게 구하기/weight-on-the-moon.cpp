#include <iostream>
using namespace std;

int main() {
    cout << fixed;
    int a = 13;
    double b = 0.165;
    double c = a * b;

    cout.precision(6);
    cout << a << " * " << b << " = " << c;

    return 0;
}
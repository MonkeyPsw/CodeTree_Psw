#include <iostream>
using namespace std;

int main() {
    cout << fixed;
    double ft = 30.48, mi = 160934;

    cout.precision(1);
    cout << 9.2 << "ft = " << ft * 9.2 << "cm";
    cout << endl;
    cout << 1.3 << "mi = " << mi * 1.3 << "cm";

    return 0;
}
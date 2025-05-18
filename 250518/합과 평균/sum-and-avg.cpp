#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;

    cin >> a >> b;

    cout << fixed;
    cout.precision(1);
    cout << a + b << " " << (a + b) / 2.;

    return 0;
}
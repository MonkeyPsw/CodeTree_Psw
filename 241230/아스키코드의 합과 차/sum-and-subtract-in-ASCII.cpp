#include <iostream>
using namespace std;

int main() {
    char a, b;

    cin >> a >> b;

    cout << a + b << " ";
    cout << (a >= b ? a - b : b - a);

    return 0;
}
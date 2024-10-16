#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6, c = 7, temp1, temp2;

    temp1 = b;
    temp2 = c;
    b = a;
    c = temp1;
    a = temp2;

    cout << a << endl << b << endl << c;
    return 0;
}
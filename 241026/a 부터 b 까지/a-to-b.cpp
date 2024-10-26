#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a << " ";
    while (a < b)
    {
        if (a % 2 != 0)
        {
            a *= 2;
        }
        else
        {
            a += 3;
        }
        if (a <= b)
            cout << a << " ";
    }
    return 0;
}
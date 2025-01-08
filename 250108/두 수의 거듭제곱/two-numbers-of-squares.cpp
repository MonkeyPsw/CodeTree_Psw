#include <iostream>

using namespace std;

int a, b;

int NumPower(int x, int y)
{
    int res = 1;

    for (int i = 0; i < y; i++)
        res *= x;

    return res;
}

int main() {
    cin >> a >> b;

    int exp = NumPower(a, b);
    cout << exp;

    return 0;
}
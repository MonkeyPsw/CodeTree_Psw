#include <iostream>

using namespace std;

int a, b;

void MakeNumber(int &x, int &y)
{
    if (a > b)
    {
        a += 25;
        b *= 2;
    }
    else
    {
        a *= 2;
        b += 25;
    }
}

int main() {
    cin >> a >> b;

    MakeNumber(a, b);

    cout << a << " " << b;

    return 0;
}
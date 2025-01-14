#include <iostream>

using namespace std;

int a, b;

void MakeNumber(int &x, int &y)
{
    if (a < b)
    {
        a += 10;
        b *= 2;
    }
    else
    {
        a *= 2;
        b += 10;
    }
}

int main() {
    cin >> a >> b;

    MakeNumber(a, b);

    cout << a << " " << b;

    return 0;
}
#include <iostream>

using namespace std;

int a, b, c;

int MakeNumber(int n)
{
    if (n < 10)
        return n;

    return n % 10 + MakeNumber(n / 10);
}

int main() {
    cin >> a >> b >> c;

    cout << MakeNumber(a * b * c);

    return 0;
}
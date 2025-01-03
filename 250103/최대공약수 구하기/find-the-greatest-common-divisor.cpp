#include <iostream>

using namespace std;

int n, m;

void GetGCD(int a, int b)
{
    int gcd;
    if (a >= b)
    {
        for (int i = 1; i <= b; i++)
        {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
        cout << gcd;
    }
    else
    {
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
        cout << gcd;
    }
}

int main() {
    cin >> n >> m;

    GetGCD(n, m);

    return 0;
}
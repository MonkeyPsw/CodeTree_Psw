#include <iostream>

using namespace std;

int a, b;

bool IsPrime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> a >> b;

    int sum = 0;

    for (int i = a; i <= b; i++)
    {
        if (IsPrime(i))
            sum += i;
    }

    cout << sum;

    return 0;
}
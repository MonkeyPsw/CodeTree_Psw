#include <iostream>

using namespace std;

int a, b;

bool IsPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool IsSumEven(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        
        if (n > 0)
            n /= 10;
    }
    
    if (sum % 2 == 0)
        return true;

    return false;
}

int main() {
    cin >> a >> b;

    int cnt = 0;

    for (int i = a; i <= b; i++)
    {
        if (IsPrime(i) && IsSumEven(i))
            cnt++;
    }

    cout << cnt;

    return 0;
}
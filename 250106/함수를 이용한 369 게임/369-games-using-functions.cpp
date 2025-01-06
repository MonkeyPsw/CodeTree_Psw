#include <iostream>

using namespace std;

int a, b;

bool IsHaveThree(int n)
{
    while (n > 0)
    {
        if (n % 10 == 3 || n % 10 == 6 || n % 10 == 9)
            return true;
        
        n /= 10;
    }
    return false;
}

bool IsMultipleThree(int n)
{
    return n % 3 == 0;
}

int main() {
    cin >> a >> b;

    int cnt = 0;

    for (int i = a; i <= b; i++)
    {
        if (IsHaveThree(i) || IsMultipleThree(i))
            cnt++;
    }

    cout << cnt;

    return 0;
}
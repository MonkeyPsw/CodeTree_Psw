#include <iostream>

using namespace std;

int a, b;

bool IsHaveThree(int n)
{
    return n / 10 % 3 == 0 || n % 10 % 3 == 0;
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
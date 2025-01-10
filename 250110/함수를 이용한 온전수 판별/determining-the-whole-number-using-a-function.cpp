#include <iostream>

using namespace std;

int a, b;


bool IsEven(int n)
{
    if (n % 2 == 0)
        return true;
    return false;
}

bool IsEndFive(int n)
{
    if (n % 10 == 5)
        return true;
    return false;
}

bool IsThreeNotNine(int n)
{
    if (n % 3 == 0 && n % 9 != 0)
        return true;
    return false;
}

int main() {
    cin >> a >> b;

    int cnt = 0;

    for (int i = a; i <= b; i++)
    {
        if (!IsEven(i) && !IsEndFive(i) && !IsThreeNotNine(i))
            cnt++;
    }

    cout << cnt;

    return 0;
}
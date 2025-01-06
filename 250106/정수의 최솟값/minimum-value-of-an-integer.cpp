#include <iostream>

using namespace std;

int a, b, c;

int FindMin(int x, int y, int z)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int main() {
    cin >> a >> b >> c;

    int min = FindMin(a, b, c);
    cout << min;

    return 0;
}
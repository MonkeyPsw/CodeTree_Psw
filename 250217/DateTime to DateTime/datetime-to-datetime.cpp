#include <iostream>

using namespace std;

int a, b, c;

int CalMin(int day, int hour, int min)
{
    return day * 24 * 60 + hour * 60 + min;
}

int main() {
    cin >> a >> b >> c;

    if (CalMin(11, 11, 11) <= CalMin(a, b, c))
        cout << CalMin(a, b, c) - CalMin(11, 11, 11);
    else
        cout << -1;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    // 1, 3, 5, 7, 8, 10, 12
    // 4, 6, 9, 11
    // 2
    int n;
    cin >> n;

    if (n <= 7)
    {
        if (n % 2 != 0)
            cout << 31;
        else if (n == 2)
            cout << 28;
        else
            cout << 30;
    }
    else
    {
        if (n % 2 == 0)
            cout << 31;
        else
            cout << 30;
    }

    return 0;
}
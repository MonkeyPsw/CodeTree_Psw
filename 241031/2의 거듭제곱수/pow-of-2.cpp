#include <iostream>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            x++;
        }
    }
    cout << x;
    return 0;
}
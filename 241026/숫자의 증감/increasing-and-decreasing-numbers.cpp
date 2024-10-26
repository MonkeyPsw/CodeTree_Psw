#include <iostream>
using namespace std;

int main() {
    char c;
    int n, i = 1;
    cin >> c >> n;

    if (c == 'A')
    {
        for (i = 1; i <= n; i++)
            cout << i << " ";
    }
    if (c == 'D')
    {
        for (i = n; i >= 1; i--)
            cout << i << " ";
    }
    return 0;
}
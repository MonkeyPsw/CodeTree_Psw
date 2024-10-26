#include <iostream>
using namespace std;

int main() {
    int a, b, i;
    cin >> a >> b;
    if (a > 0)
    {
        for (i = 0; i < b; i++)
            cout << a;
    }
    else
        cout << 0;
    return 0;
}
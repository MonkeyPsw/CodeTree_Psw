#include <iostream>

using namespace std;

int a[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> a[i];

    if (a[0] + 1 == a[1] && a[1] + 1 == a[2])
        cout << 0;
    else
    {
        if (a[1] - a[0] > a[2] - a[1])
            cout << a[1] - a[0] - 1;
        else
            cout << a[2] - a[1] - 1;
    }
    
    return 0;
}
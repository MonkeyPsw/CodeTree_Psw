#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    
    cin >> n;
    cnt = n;

    for (int i = n; i >= 1; i--)
    {
        if (i % 4 != 0 || i % 100 == 0 && i % 400 != 0)
            cnt--;
    }

    cout << cnt;
    return 0;
}
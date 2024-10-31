#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;;
    while (true)
    {
        cin >> n;
        if (cnt >= 3)
            break;
        if (n % 2 == 0)
        {
            cout << n / 2 << endl;
            cnt++;
        }
    }
    return 0;
}
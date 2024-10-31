#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0, sum = 0;

    while (true)
    {
        cin >> n;
        if (n >= 20 && n < 30)
        {
            sum += n;
            cnt++;
        }
        else
        {
            cout << fixed;
            cout.precision(2);
            cout << (double)sum / cnt;
            break;
        }
    }

    return 0;
}
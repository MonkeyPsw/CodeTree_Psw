#include <iostream>
using namespace std;

int main() {
    int a, b, cnt = 0, sum = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i % 5 == 0 || i % 7 == 0)
        {
            sum += i;
            cnt++;
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << sum << " ";
    cout << (double)sum / cnt;
    return 0;
}
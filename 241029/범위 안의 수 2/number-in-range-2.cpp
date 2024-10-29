#include <iostream>
using namespace std;

int main() {
    int num, cnt = 0, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        if (num >= 0 && num <= 200)
        {
            sum += num;
            cnt++;
        }
    }
    cout << sum << " ";
    cout << fixed;
    cout.precision(1);
    cout << (double)sum / cnt;
    return 0;
}
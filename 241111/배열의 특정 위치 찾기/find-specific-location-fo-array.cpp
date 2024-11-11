#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int sum1 = 0, sum2 = 0, cnt = 0;
    for (int i = 1; i <= 10; i++)
    {
        cin >> arr[i - 1];
        if (i % 2 == 0)
            sum1 += arr[i - 1];
        if (i % 3 == 0)
        {
            sum2 += arr[i - 1];
            cnt++;
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << sum1 << " " << (double)sum2 / cnt;
    return 0;
}
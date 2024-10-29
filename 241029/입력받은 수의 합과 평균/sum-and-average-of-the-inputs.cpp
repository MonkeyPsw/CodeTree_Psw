#include <iostream>
using namespace std;

int main() {
    int n, num, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
    }
    cout << sum << " ";
    cout << fixed;
    cout.precision(1);
    cout << (double)sum / n;
    return 0;
}
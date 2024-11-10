#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int num, sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        cin >> arr[i];
        if (arr[i] < 250)
            sum += arr[i];
        else
        {
            cout << fixed;
            cout.precision(1);
            cout << sum << " " << (double)sum / i;
            break;
        }
    }
    return 0;
}
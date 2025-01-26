#include <iostream>

using namespace std;

int n;
int arr[10];

int GetGCD(int a, int b)
{
    return b ? GetGCD(b, a % b) : a;
}

int GetLCM(int arr[], int length)
{
    if (length == 1)
        return arr[0];

    int gcd = GetGCD(arr[length - 2], arr[length - 1]);

    arr[length - 2] *= arr[length - 1] / gcd;

    return GetLCM(arr, length - 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << GetLCM(arr, n);

    return 0;
}
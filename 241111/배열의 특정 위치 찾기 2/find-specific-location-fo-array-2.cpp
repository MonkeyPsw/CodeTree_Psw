#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int oddSum = 0, evenSum = 0;
    for (int i = 0; i <= 9; i++)
    {
        cin >> arr[i];
        if (i % 2 == 0)
            oddSum += arr[i];
        else
            evenSum += arr[i];
    }
    cout << (oddSum >= evenSum ? oddSum - evenSum : evenSum - oddSum);
    return 0;
}
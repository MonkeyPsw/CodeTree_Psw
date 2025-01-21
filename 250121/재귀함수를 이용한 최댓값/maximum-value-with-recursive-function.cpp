#include <iostream>

using namespace std;

int n;
int arr[100];

int FindMax(int arr[], int length)
{
    if (length == 1)
        return arr[0];

    if (arr[length - 1] >= arr[length - 2])
    {
        arr[length - 2] = arr[length - 1];
        return FindMax(arr, length - 1);
    }
    else
        return FindMax(arr, length - 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << FindMax(arr, n);

    return 0;
}
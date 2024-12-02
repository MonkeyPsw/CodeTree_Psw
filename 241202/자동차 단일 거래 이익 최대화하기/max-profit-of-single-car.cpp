#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[minIdx])
            minIdx = i;
    }

    int max = 0;
    for (int i = minIdx; i < n - 1; i++)
    {
        for (int j = minIdx + 1; j < n; j++)
        {
            if (arr[j] - arr[i] > max)
                max = arr[j] - arr[i];
        }
    }

    cout << max;
    return 0;
}
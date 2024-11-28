#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        int max = arr[i];
        int idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= max)
            {
                max = arr[j];
                idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = max;
        arr[idx] = temp;
    }

    cout << arr[0] << " " << arr[1];
    return 0;
}
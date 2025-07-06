#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100000];
int maxVal, k;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        maxVal = max(maxVal, arr[i]);
    }

    while (maxVal > 0)
    {
        maxVal /= 10;
        k++;
    }

    int digit = 1;

    for (int pos = k - 1; pos >= 0; pos--)
    {
        vector<int> arr_digits[10];

        for (int i = 0; i < n; i++)
            arr_digits[(arr[i] / digit) % 10].push_back(arr[i]);
        

        int cnt = 0;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < (int)arr_digits[i].size(); j++)
                arr[cnt++] = arr_digits[i][j];
        }

        digit *= 10;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
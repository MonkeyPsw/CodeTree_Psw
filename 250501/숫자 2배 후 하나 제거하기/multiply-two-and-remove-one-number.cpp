#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int n;
int arr[100];
int ans = INT_MAX;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] *= 2;

        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            int arr2[99] = {};

            for (int k = 0; k < n; k++)
            {
                if (j == k)
                    continue;
                arr2[cnt++] = arr[k];
            }

            int sum = 0;

            for (int k = 0; k < n - 2; k++)
                sum += abs(arr2[k] -  arr2[k + 1]);

            ans = min(ans, sum);
        }

        arr[i] /= 2;
    }

    cout << ans;

    return 0;
}
#include <iostream>

using namespace std;

int n, k;
int arr[1000];
int preSum[1000];
int ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    preSum[0] = arr[0];
    for (int i = 1; i < n; i++)
        preSum[i] = preSum[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (preSum[j] - preSum[i] + arr[i] == k)
                ans++;
        }
    }

    cout << ans;

    return 0;
}

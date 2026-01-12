#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[100001];
int preSum[100001];
int ans = INT_MIN;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    preSum[0] = 0;
    for (int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + arr[i];
    
    for (int i = k; i <= n; i++)
        ans = max(ans, preSum[i] - preSum[i - k]);

    cout << ans;

    return 0;
}
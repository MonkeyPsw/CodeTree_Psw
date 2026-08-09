#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[500];
long long prefix[501];
long long dp[500][500];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;

            dp[i][j] = (1LL << 60);

            long long sum = prefix[j + 1] - prefix[i];

            for (int k = i; k < j; k++) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] + dp[k + 1][j] + sum
                );
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}
#include <iostream>

using namespace std;

const int MOD = 10007;

int n;
int points[200];
int dp[200][200];
int next_dp[200][200];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    dp[0][0] = 1;

    for (int k = 1; k < n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                next_dp[i][j] = 0;
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i][j] == 0)
                    continue;

                // k번 수를 선택하지 않는 경우
                next_dp[i][j] += dp[i][j];
                next_dp[i][j] %= MOD;

                // 오른쪽으로 이동할 때 선택하는 경우
                if (points[i] < points[k]) {
                    next_dp[k][j] += dp[i][j];
                    next_dp[k][j] %= MOD;
                }

                // 왼쪽으로 돌아올 때 선택하는 경우
                if (points[j] < points[k]) {
                    next_dp[i][k] += dp[i][j];
                    next_dp[i][k] %= MOD;
                }
            }
        }

        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = next_dp[i][j];
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (points[i] < points[n - 1] &&
                points[j] < points[n - 1]) {
                ans += dp[i][j];
                ans %= MOD;
            }
        }
    }

    cout << ans;

    return 0;
}
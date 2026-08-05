#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

const long long INF = (1LL << 60);

int n, m;
int points[2000];
int x[2000];
bool forbidden[2000];
long long dp[2001][2001];

long long GetCost(int last, int next) {
    if (last == 0)
        return 0;

    return abs((long long)points[last - 1] - points[next]);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> x[i];
        forbidden[x[i] - 1] = true;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == INF)
                continue;

            int next = max(i, j);

            if (next == n)
                continue;

            dp[next + 1][j] = min(
                dp[next + 1][j],
                dp[i][j] + GetCost(i, next)
            );

            if (!forbidden[next]) {
                dp[i][next + 1] = min(
                    dp[i][next + 1],
                    dp[i][j] + GetCost(j, next)
                );
            }
        }
    }

    long long answer = INF;

    for (int i = 0; i <= n; i++) {
        answer = min(answer, dp[n][i]);
        answer = min(answer, dp[i][n]);
    }

    cout << answer;

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = (1LL << 60);

int n;
int cards[2000];
long long dp[2001][2001];

long long GetCost(int index, int next) {
    if (index == 0)
        return 0;

    return abs(cards[index - 1] - cards[next]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int next = max(i, j);

            if (next == n || dp[i][j] == INF)
                continue;

            dp[next + 1][j] = min(
                dp[next + 1][j],
                dp[i][j] + GetCost(i, next)
            );

            dp[i][next + 1] = min(
                dp[i][next + 1],
                dp[i][j] + GetCost(j, next)
            );
        }
    }

    long long answer = INF;

    for (int i = 0; i <= n; i++) {
        answer = min(answer, dp[i][n]);
        answer = min(answer, dp[n][i]);
    }

    cout << answer;

    return 0;
}
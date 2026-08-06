#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

const long long INF = (1LL << 60);

int n, m;
int cards[50];
long long dp[2][51][51][51];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= m; k++) {
                    dp[t][i][j][k] = INF;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;

    for (int next = 1; next <= n; next++) {
        int cur = (next - 1) % 2;
        int nxt = next % 2;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= m; k++) {
                    dp[nxt][i][j][k] = INF;
                }
            }
        }

        for (int i = 0; i < next; i++) {
            for (int j = 0; j < next; j++) {
                for (int k = 0; k <= m; k++) {
                    if (dp[cur][i][j][k] == INF)
                        continue;

                    long long firstCost = 0;
                    if (i != 0)
                        firstCost = abs((long long)cards[i - 1] - cards[next - 1]);

                    dp[nxt][next][j][k] = min(
                        dp[nxt][next][j][k],
                        dp[cur][i][j][k] + firstCost
                    );

                    long long secondCost = 0;
                    if (j != 0)
                        secondCost = abs((long long)cards[j - 1] - cards[next - 1]);

                    dp[nxt][i][next][k] = min(
                        dp[nxt][i][next][k],
                        dp[cur][i][j][k] + secondCost
                    );

                    if (k < m) {
                        dp[nxt][i][j][k + 1] = min(
                            dp[nxt][i][j][k + 1],
                            dp[cur][i][j][k]
                        );
                    }
                }
            }
        }
    }

    long long answer = INF;
    int last = n % 2;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= m; k++) {
                answer = min(answer, dp[last][i][j][k]);
            }
        }
    }

    cout << answer;

    return 0;
}
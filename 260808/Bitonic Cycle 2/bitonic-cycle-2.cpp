#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = (1LL << 60);

int n;
int x[1000], y[1000];
long long dp[1000][1000][2];

long long Dist(int a, int b) {
    long long dx = x[a] - x[b];
    long long dy = y[a] - y[b];

    return dx * dx + dy * dy;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    pair<int, int> points[1000];

    for (int i = 0; i < n; i++) {
        points[i] = {x[i], y[i]};
    }

    sort(points, points + n);

    for (int i = 0; i < n; i++) {
        x[i] = points[i].first;
        y[i] = points[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j][0] == INF && dp[i][j][1] == INF)
                continue;

            int next = max(i, j) + 1;

            if (next >= n)
                continue;

            for (int used = 0; used <= 1; used++) {
                if (dp[i][j][used] == INF)
                    continue;

                // i번 점에서 next번 점으로 이동
                dp[next][j][used] = min(
                    dp[next][j][used],
                    dp[i][j][used] + Dist(i, next)
                );

                // 이번 이동의 거리를 0으로 계산
                if (!used) {
                    dp[next][j][1] = min(
                        dp[next][j][1],
                        dp[i][j][0]
                    );
                }

                // j번 점에서 next번 점으로 이동
                dp[i][next][used] = min(
                    dp[i][next][used],
                    dp[i][j][used] + Dist(j, next)
                );

                // 이번 이동의 거리를 0으로 계산
                if (!used) {
                    dp[i][next][1] = min(
                        dp[i][next][1],
                        dp[i][j][0]
                    );
                }
            }
        }
    }

    long long answer = INF;

    for (int i = 0; i < n - 1; i++) {
        answer = min(
            answer,
            dp[i][n - 1][1] + Dist(i, n - 1)
        );
    }

    cout << answer;

    return 0;
}
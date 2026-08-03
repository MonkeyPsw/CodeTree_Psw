#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[1000], y[1000];
long long dp[1000][1000];

long long GetDistance(int a, int b) {
    long long dx = x[a] - x[b];
    long long dy = y[a] - y[b];

    return dx * dx + dy * dy;
}

int main() {
    cin >> n;

    pair<int, int> points[1000];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        points[i] = {x[i], y[i]};
    }

    sort(points, points + n);

    for (int i = 0; i < n; i++) {
        x[i] = points[i].first;
        y[i] = points[i].second;
    }

    dp[0][1] = GetDistance(0, 1);

    for (int j = 2; j < n; j++) {
        for (int i = 0; i < j - 1; i++) {
            dp[i][j] = dp[i][j - 1] + GetDistance(j - 1, j);
        }

        dp[j - 1][j] = 1LL << 60;

        for (int k = 0; k < j - 1; k++) {
            dp[j - 1][j] = min(
                dp[j - 1][j],
                dp[k][j - 1] + GetDistance(k, j)
            );
        }
    }

    cout << dp[n - 2][n - 1] + GetDistance(n - 2, n - 1);

    return 0;
}
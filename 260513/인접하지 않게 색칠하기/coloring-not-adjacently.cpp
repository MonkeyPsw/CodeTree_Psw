#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int from[100000], to[100000];
int value[100001];

vector<int> edges[100001];
bool visited[100001];

long long dp[100001][11][2];
int subtree_size[100001];

const long long INF = -(1LL << 60);

void DFS(int x) {
    visited[x] = true;

    // 초기화
    for (int i = 0; i <= k; i++) {
        dp[x][i][0] = INF;
        dp[x][i][1] = INF;
    }

    dp[x][0][0] = 0;
    dp[x][1][1] = value[x];
    subtree_size[x] = 1;

    // 자식들 하나씩 merge
    for (int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];

        if (visited[y]) continue;

        DFS(y);

        static long long temp[11][2];

        for (int a = 0; a <= k; a++) {
            temp[a][0] = INF;
            temp[a][1] = INF;
        }

        for (int a = 0; a <= min(subtree_size[x], k); a++) {
            for (int b = 0; b <= min(subtree_size[y], k - a); b++) {

                // x 선택 안 함
                if (dp[x][a][0] != INF) {
                    long long child_best =
                        max(dp[y][b][0], dp[y][b][1]);

                    if (child_best != INF) {
                        temp[a + b][0] = max(
                            temp[a + b][0],
                            dp[x][a][0] + child_best
                        );
                    }
                }

                // x 선택 함 → 자식은 선택 못 함
                if (dp[x][a][1] != INF &&
                    dp[y][b][0] != INF) {

                    temp[a + b][1] = max(
                        temp[a + b][1],
                        dp[x][a][1] + dp[y][b][0]
                    );
                }
            }
        }

        subtree_size[x] += subtree_size[y];

        for (int a = 0; a <= k; a++) {
            dp[x][a][0] = temp[a][0];
            dp[x][a][1] = temp[a][1];
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        edges[from[i]].push_back(to[i]);
        edges[to[i]].push_back(from[i]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    cin >> k;

    DFS(1);

    long long ans = 0;

    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[1][i][0]);
        ans = max(ans, dp[1][i][1]);
    }

    cout << ans;

    return 0;
}
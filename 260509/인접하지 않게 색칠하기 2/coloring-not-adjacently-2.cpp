#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int from[100000], to[100000];
int a[100001];

vector<int> graph[100001];
int child[100001][2];
bool visited[100001];

int dp[100001][11][2];
const int INF = -1e9;

void MakeTree(int x) {
    visited[x] = true;

    int idx = 0;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        child[x][idx++] = next;
        MakeTree(next);
    }
}

void DFS(int x) {
    for (int i = 0; i <= k; i++) {
        dp[x][i][0] = INF;
        dp[x][i][1] = INF;
    }

    // 리프 노드
    if (child[x][0] == 0 && child[x][1] == 0) {
        dp[x][0][0] = 0;
        dp[x][1][1] = a[x];
        return;
    }

    int l = child[x][0];
    int r = child[x][1];

    DFS(l);
    DFS(r);

    // x를 선택하지 않는 경우
    dp[x][0][0] = 0;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j + i <= k; j++) {
            int leftMax = max(dp[l][i][0], dp[l][i][1]);
            int rightMax = max(dp[r][j][0], dp[r][j][1]);

            dp[x][i + j][0] = max(dp[x][i + j][0],
                                   leftMax + rightMax);
        }
    }

    // x를 선택하는 경우 (자식은 선택 불가)
    dp[x][1][1] = a[x];

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j + i + 1 <= k; j++) {
            if (dp[l][i][0] == INF) continue;
            if (dp[r][j][0] == INF) continue;

            dp[x][i + j + 1][1] = max(
                dp[x][i + j + 1][1],
                a[x] + dp[l][i][0] + dp[r][j][0]
            );
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> k;

    MakeTree(1);
    DFS(1);

    cout << max(dp[1][k][0], dp[1][k][1]) << endl;

    return 0;
}
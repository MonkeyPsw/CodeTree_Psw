#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int values[10001];
int from[10000], to[10000];

vector<int> graph[10001];
bool visited[10001];

int dp[10001][2];
bool selected[10001];

vector<int> ans;

void DFS(int x) {
    visited[x] = true;

    dp[x][0] = 0;
    dp[x][1] = values[x];

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        DFS(next);

        dp[x][0] += max(dp[next][0], dp[next][1]);
        dp[x][1] += dp[next][0];
    }
}

void Trace(int x, bool parentSelected) {
    visited[x] = true;

    bool nowSelected = false;

    if (!parentSelected && dp[x][1] > dp[x][0]) {
        nowSelected = true;
        ans.push_back(x);
    }

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        Trace(next, nowSelected);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    DFS(1);

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    Trace(1, false);

    cout << max(dp[1][0], dp[1][1]) << endl;

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int from[9999];
int to[9999];
int values[10000];

vector<int> graph[10001];
bool visited[10001];

int dp[10001][2];

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

    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
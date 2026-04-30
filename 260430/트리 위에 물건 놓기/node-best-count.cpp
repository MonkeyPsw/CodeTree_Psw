#include <iostream>
#include <vector>

using namespace std;

int n;
int from[100000];
int to[100000];

vector<int> graph[100001];
bool visited[100001];
int dp[100001][2];

void DFS(int x) {
    visited[x] = true;

    dp[x][0] = 0;
    dp[x][1] = 1;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        DFS(next);

        dp[x][0] += dp[next][1];
        dp[x][1] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    DFS(1);

    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
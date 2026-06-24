#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int x[100000], y[100000];

const int MOD = 1000000007;

vector<int> graph[100001];
int indegree[100001];
long long dp[100001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];

        graph[x[i]].push_back(y[i]);
        indegree[y[i]]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    dp[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            dp[next] = (dp[next] + dp[cur]) % MOD;
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << dp[n];

    return 0;
}
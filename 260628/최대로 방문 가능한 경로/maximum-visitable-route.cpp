#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int x[100000], y[100000];

vector<int> graph[100001];
int indegree[100001];
int dp[100001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];

        graph[x[i]].push_back(y[i]);
        indegree[y[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        order.push_back(cur);

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
    }

    dp[n] = 1;

    for (int i = order.size() - 1; i >= 0; i--) {
        int cur = order[i];

        for (int j = 0; j < graph[cur].size(); j++) {
            int next = graph[cur][j];

            if (dp[next] != -1) {
                dp[cur] = max(dp[cur], dp[next] + 1);
            }
        }
    }

    if (dp[1] == -1) {
        cout << -1;
        return 0;
    }

    vector<int> answer;
    int cur = 1;

    while (cur != n) {
        answer.push_back(cur);

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if (dp[next] == dp[cur] - 1) {
                cur = next;
                break;
            }
        }
    }

    answer.push_back(n);

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
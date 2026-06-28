#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int from[100000], to[100000], cost[100000];

vector<pair<int, int>> graph[100001];
vector<pair<int, int>> reverse_graph[100001];
int indegree[100001];
int reverse_indegree[100001];
long long dp1[100001];
long long dp2[100001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> cost[i];

        graph[from[i]].push_back({to[i], cost[i]});
        reverse_graph[to[i]].push_back({from[i], cost[i]});

        indegree[to[i]]++;
        reverse_indegree[from[i]]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        dp1[i] = -1;
    }

    dp1[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int c = graph[cur][i].second;

            if (dp1[cur] != -1) {
                dp1[next] = max(dp1[next], dp1[cur] + c);
            }

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dp2[i] = -1;
    }

    dp2[n] = 0;

    for (int i = 1; i <= n; i++) {
        if (reverse_indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < reverse_graph[cur].size(); i++) {
            int next = reverse_graph[cur][i].first;
            int c = reverse_graph[cur][i].second;

            if (dp2[cur] != -1) {
                dp2[next] = max(dp2[next], dp2[cur] + c);
            }

            reverse_indegree[next]--;

            if (reverse_indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    long long answer_time = dp1[n];
    int answer_count = 0;

    for (int i = 0; i < m; i++) {
        if (dp1[from[i]] != -1 && dp2[to[i]] != -1 &&
            dp1[from[i]] + cost[i] + dp2[to[i]] == answer_time) {
            answer_count++;
        }
    }

    cout << answer_time << " " << answer_count;

    return 0;
}
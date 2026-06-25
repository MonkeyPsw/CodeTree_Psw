#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int from[100000], to[100000];

vector<int> graph[1001];
int indegree[1001];
int pressure[1001];
int max_parent[1001];
int max_count[1001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        indegree[to[i]]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pressure[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if (pressure[cur] > max_parent[next]) {
                max_parent[next] = pressure[cur];
                max_count[next] = 1;
            } else if (pressure[cur] == max_parent[next]) {
                max_count[next]++;
            }

            indegree[next]--;

            if (indegree[next] == 0) {
                if (max_count[next] >= 2) {
                    pressure[next] = max_parent[next] + 1;
                } else {
                    pressure[next] = max_parent[next];
                }

                q.push(next);
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        answer = max(answer, pressure[i]);
    }

    cout << answer;

    return 0;
}
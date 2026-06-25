#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int x[100], y[100], z[100];

vector<pair<int, int>> graph[101];
int indegree[101];
int need[101][101];
bool is_basic[101];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        is_basic[i] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> z[i];

        graph[y[i]].push_back({x[i], z[i]});
        indegree[x[i]]++;
        is_basic[x[i]] = false;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (is_basic[i]) {
            need[i][i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int cnt = graph[cur][i].second;

            for (int j = 1; j <= n; j++) {
                need[next][j] += need[cur][j] * cnt;
            }

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (is_basic[i] && need[n][i] > 0) {
            cout << i << " " << need[n][i] << endl;
        }
    }

    return 0;
}
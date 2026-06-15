#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from[100000], to[100000];

vector<int> graph[100001];
int indegree[100001];

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
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cnt++;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (cnt == n) {
        cout << "Consistent";
    } else {
        cout << "Inconsistent";
    }

    return 0;
}
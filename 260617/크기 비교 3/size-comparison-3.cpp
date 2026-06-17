#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from[100000], to[100000];

vector<int> graph[32001];
int indegree[32001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        indegree[to[i]]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    return 0;
}
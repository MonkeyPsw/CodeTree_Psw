#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int x[100000], y[100000];

vector<int> rev_graph[100005];
int outdegree[100005];
int answer[100005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < m; i++) {
        rev_graph[y[i]].push_back(x[i]);
        outdegree[x[i]]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (outdegree[i] == 0) {
            pq.push(i);
        }
    }

    int val = n;
    int visited_count = 0;

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        
        visited_count++;
        answer[cur] = val--;

        for (int next : rev_graph[cur]) {
            outdegree[next]--;
            if (outdegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    if (visited_count < n) {
        cout << -1;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << answer[i] << (i == n ? "" : " ");
        }
    }

    return 0;
}
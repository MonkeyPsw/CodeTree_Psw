#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m1, m2;
int a1[100000], b1[100000];
int a2[100000], b2[100000];

vector<int> graph[100001];
int indegree[100001];

int main() {
    cin >> n >> m1 >> m2;

    for (int i = 0; i < m1; i++) {
        cin >> a1[i] >> b1[i];

        graph[a1[i]].push_back(b1[i]);
        indegree[b1[i]]++;
    }

    for (int i = 0; i < m2; i++) {
        cin >> a2[i] >> b2[i];
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
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
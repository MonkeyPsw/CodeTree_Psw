#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
string nodes[1000];
string x[500000], y[500000];

map<string, int> idx;
vector<int> graph[1000];
vector<int> child[1000];
int indegree[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> nodes[i];

    sort(nodes, nodes + n);

    for (int i = 0; i < n; i++) {
        idx[nodes[i]] = i;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];

        int a = idx[x[i]];
        int b = idx[y[i]];

        graph[b].push_back(a);
        indegree[a]++;
    }

    queue<int> q;
    vector<int> root;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            root.push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            indegree[next]--;

            if (indegree[next] == 0) {
                child[cur].push_back(next);
                q.push(next);
            }
        }
    }

    cout << root.size() << endl;

    for (int i = 0; i < root.size(); i++) {
        cout << nodes[root[i]] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        sort(child[i].begin(), child[i].end());

        cout << nodes[i] << " " << child[i].size() << " ";

        for (int j = 0; j < child[i].size(); j++) {
            cout << nodes[child[i][j]] << " ";
        }

        cout << endl;
    }

    return 0;
}
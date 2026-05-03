#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, d;
int from[100000], to[100000];

vector<int> graph[100001];
bool visited[100001];
int maxDepth[100001];
int ans = 0;

void DFS(int x) {
    visited[x] = true;
    maxDepth[x] = 0;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        DFS(next);

        maxDepth[x] = max(maxDepth[x], maxDepth[next] + 1);
    }
}

void CountDFS(int x) {
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        if (maxDepth[next] >= d) {
            ans++;
            CountDFS(next);
        }
    }
}

int main() {
    cin >> n >> s >> d;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    DFS(s);

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    CountDFS(s);

    cout << ans * 2 << endl;

    return 0;
}
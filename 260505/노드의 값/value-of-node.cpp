#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
int values[10001];
int from[10000];
int to[10000];

vector<int> graph[10001];
bool visited[10001];

long long ans = 0;

int DFS(int x) {
    visited[x] = true;

    int sum = values[x];

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        int child = DFS(next);
        ans += abs(child);
        sum += child;
    }

    return sum - 1;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    DFS(1);

    cout << ans << endl;

    return 0;
}
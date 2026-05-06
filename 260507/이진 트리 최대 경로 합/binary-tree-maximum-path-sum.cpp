#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int from[30000], to[30000];
int value[30001];

vector<int> graph[30001];
bool visited[30001];

int ans = -1000000000;

int DFS(int x) {
    visited[x] = true;

    int max1 = 0;
    int max2 = 0;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        int child = DFS(next);

        if (child > max1) {
            max2 = max1;
            max1 = child;
        }
        else if (child > max2) {
            max2 = child;
        }
    }

    ans = max(ans, value[x] + max1 + max2);

    return max(0, value[x] + max1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    DFS(1);

    cout << ans << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
int from[100000], to[100000];
int U[100000];

vector<int> graph[100001];
bool visited[100001];
int subtree_size[100001];

int DFS(int x) {
    visited[x] = true;
    subtree_size[x] = 1;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) continue;

        subtree_size[x] += DFS(next);
    }

    return subtree_size[x];
}

int main() {
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> U[i];
    }

    DFS(r);

    for (int i = 0; i < q; i++) {
        cout << subtree_size[U[i]] << endl;
    }

    return 0;
}
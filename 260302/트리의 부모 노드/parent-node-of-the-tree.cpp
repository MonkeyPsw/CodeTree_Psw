#include <iostream>
#include <vector>

using namespace std;

int n;
int from[100000], to[100000];
vector<int> tree[100001];
int parent[100001];
bool visited[100001];

void DFS(int node)
{
    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i];

        if (!visited[next])
        {
            visited[next] = true;
            parent[next] = node;
            DFS(next);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        tree[from[i]].push_back(to[i]);
        tree[to[i]].push_back(from[i]);
    }

    DFS(1);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << endl;

    return 0;
}
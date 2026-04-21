#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 500;

int n, m;
int from[125000], to[125000];
vector<int> graph[MAX_N + 1];
bool visited[MAX_N + 1];
int vertexCount;
int edgeCount;
int ans;

void DFS(int node)
{
    visited[node] = true;
    vertexCount++;

    edgeCount += graph[node].size();

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];

        if (!visited[next])
            DFS(next);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 0; i < m; i++)
    {
        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        vertexCount = 0;
        edgeCount = 0;

        DFS(i);

        edgeCount /= 2;

        if (edgeCount == vertexCount - 1)
            ans++;
    }

    cout << ans;

    return 0;
}
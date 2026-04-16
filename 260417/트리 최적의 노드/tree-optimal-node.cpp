#include <iostream>
#include <vector>

using namespace std;

int n;
int from[100000];
int to[100000];
vector<int> tree[100001];
bool visited[100001];
int farthestNode;
int maxDist;

void DFS(int node, int dist)
{
    visited[node] = true;

    if (dist > maxDist)
    {
        maxDist = dist;
        farthestNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i];

        if (!visited[next])
            DFS(next, dist + 1);
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

    DFS(1, 0);

    for (int i = 1; i <= n; i++)
        visited[i] = false;

    maxDist = 0;
    DFS(farthestNode, 0);

    cout << (maxDist + 1) / 2;

    return 0;
}
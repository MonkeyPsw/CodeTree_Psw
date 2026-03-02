#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;

int n;
int from[100000];
int to[100000];
int dist[100000];
vector<pair<int, int> > tree[MAX_N + 1];
bool visited[MAX_N + 1];
int farthestNode;
int maxDist;

void DFS(int node, int accumulatedDist)
{
    visited[node] = true;

    if (accumulatedDist > maxDist)
    {
        maxDist = accumulatedDist;
        farthestNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i].first;
        int weight = tree[node][i].second;

        if (!visited[next])
            DFS(next, accumulatedDist + weight);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> dist[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        tree[from[i]].push_back(make_pair(to[i], dist[i]));
        tree[to[i]].push_back(make_pair(from[i], dist[i]));
    }

    DFS(1, 0);

    for (int i = 1; i <= n; i++)
        visited[i] = false;

    maxDist = 0;
    DFS(farthestNode, 0);

    cout << maxDist;

    return 0;
}
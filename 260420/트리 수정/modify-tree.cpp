#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2000;

int n;
int from[MAX_N];
int to[MAX_N];
int weight[MAX_N];
vector<pair<int, int> > tree[MAX_N];

int blockA, blockB;
bool visited[MAX_N];
int farthestNode;
long long maxDist;

void DFS(int node, long long dist)
{
    visited[node] = true;

    if (dist > maxDist)
    {
        maxDist = dist;
        farthestNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i].first;
        int cost = tree[node][i].second;

        if ((node == blockA && next == blockB) || (node == blockB && next == blockA))
            continue;

        if (!visited[next])
            DFS(next, dist + cost);
    }
}

long long GetDiameter(int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = false;

    maxDist = 0;
    farthestNode = start;
    DFS(start, 0);

    int startNode = farthestNode;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    maxDist = 0;
    farthestNode = startNode;
    DFS(startNode, 0);

    return maxDist;
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> weight[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        tree[from[i]].push_back(make_pair(to[i], weight[i]));
        tree[to[i]].push_back(make_pair(from[i], weight[i]));
    }

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        blockA = from[i];
        blockB = to[i];

        long long leftDiameter = GetDiameter(from[i]);
        long long rightDiameter = GetDiameter(to[i]);

        long long cand = leftDiameter + weight[i] + rightDiameter;

        if (cand > ans)
            ans = cand;
    }

    cout << ans;

    return 0;
}
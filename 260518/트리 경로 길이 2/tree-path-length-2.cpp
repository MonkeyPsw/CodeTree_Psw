#include <iostream>
#include <vector>

using namespace std;

int n, q;
int from[100000], to[100000], weight[100000];
int st[100000], ed[100000];

vector<int> graph[100001];
vector<int> cost[100001];

int depth[100001];
int parent[100001][17];
long long dist[100001];
bool visited[100001];

void dfs(int now, int d, long long sum)
{
    visited[now] = true;
    depth[now] = d;
    dist[now] = sum;

    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];

        if (visited[next]) continue;

        parent[next][0] = now;
        dfs(next, d + 1, sum + cost[now][i]);
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    // 깊이 맞추기
    int diff = depth[x] - depth[y];
    for (int i = 0; i < 17; i++)
    {
        if (diff & (1 << i))
            x = parent[x][i];
    }

    if (x == y) return x;

    // 같이 올리기
    for (int i = 16; i >= 0; i--)
    {
        if (parent[x][i] != parent[y][i])
        {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> weight[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);

        cost[from[i]].push_back(weight[i]);
        cost[to[i]].push_back(weight[i]);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> st[i] >> ed[i];
    }

    // DFS
    dfs(1, 0, 0);

    // sparse table
    for (int j = 1; j < 17; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    // 쿼리 처리
    for (int i = 0; i < q; i++)
    {
        int x = st[i];
        int y = ed[i];

        int p = lca(x, y);

        // 거리 합
        long long ans = dist[x] + dist[y] - 2 * dist[p];

        cout << ans << endl;
    }

    return 0;
}
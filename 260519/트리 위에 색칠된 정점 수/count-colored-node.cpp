#include <iostream>
#include <vector>

using namespace std;

int n, k, q;
int from[100000], to[100000];
int colored[100000];
int query_start[100000], query_end[100000];

vector<int> graph[100001];

int depth[100001];
int parent[100001][17];
bool visited[100001];

int is_colored[100001];
int color_sum[100001];

void dfs(int now, int d, int sum)
{
    visited[now] = true;
    depth[now] = d;
    color_sum[now] = sum + is_colored[now];

    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];

        if (visited[next]) continue;

        parent[next][0] = now;
        dfs(next, d + 1, color_sum[now]);
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
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> colored[i];
        is_colored[colored[i]] = 1;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> query_start[i] >> query_end[i];
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
        int x = query_start[i];
        int y = query_end[i];

        int p = lca(x, y);

        // 경로 위 색칠된 정점 수
        int ans = color_sum[x] + color_sum[y] - 2 * color_sum[p] + is_colored[p];

        cout << ans << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, q;
int from[100000], to[100000];
int query_from[100000], query_to[100000];

vector<int> graph[100001];
int depth[100001];
int parent[100001][17];
bool visited[100001];

void dfs(int now, int d)
{
    visited[now] = true;
    depth[now] = d;

    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];

        if (visited[next]) continue;

        parent[next][0] = now;
        dfs(next, d + 1);
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

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> query_from[i] >> query_to[i];
    }

    // DFS로 depth, parent[][0] 구하기
    dfs(1, 0);

    // sparse table 만들기
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
        int x = query_from[i];
        int y = query_to[i];

        int p = lca(x, y);

        // 경로 길이(노드 개수)
        int ans = depth[x] + depth[y] - 2 * depth[p] + 1;

        cout << ans << endl;
    }

    return 0;
}
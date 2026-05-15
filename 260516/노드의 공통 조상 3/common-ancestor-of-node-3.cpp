#include <iostream>
#include <vector>

using namespace std;

int n, q;
int from[50000], to[50000];
int a[10000], b[10000], c[10000];

vector<int> graph[50001];
int depth[50001];
int parent[50001][17];
bool visited[50001];

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
    // 깊이 맞추기
    if (depth[x] < depth[y])
        swap(x, y);

    int diff = depth[x] - depth[y];

    for (int i = 0; i < 17; i++)
    {
        if (diff & (1 << i))
            x = parent[x][i];
    }

    // 이미 같으면 바로 반환
    if (x == y) return x;

    // 가장 큰 조상부터 같이 올리기
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
        cin >> a[i] >> b[i] >> c[i];
    }

    // 1번을 루트로 DFS
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
        // 세 노드의 공통 조상 = lca(lca(a,b), c)
        int ab = lca(a[i], b[i]);
        int ans = lca(ab, c[i]);

        cout << ans << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, q;
int from[100000], to[100000];
int query_from[10], query_to[10];

vector<int> graph[100001];
int parent[100001];
int depth[100001];
bool visited[100001];

void dfs(int now, int d)
{
    visited[now] = true;
    depth[now] = d;

    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];

        if (visited[next]) continue;

        parent[next] = now;
        dfs(next, d + 1);
    }
}

int lca(int a, int b)
{
    // 깊이 맞추기
    while (depth[a] > depth[b])
        a = parent[a];

    while (depth[b] > depth[a])
        b = parent[b];

    // 같이 올라가기
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
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

    // 루트 1 기준 DFS
    parent[1] = 0;
    dfs(1, 0);

    // 쿼리 처리
    for (int i = 0; i < q; i++)
    {
        cout << lca(query_from[i], query_to[i]) << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int n, m;
int from[10000], to[10000];
int graph[1001][1001];
int visited[1001];
int ans;

void DFS(int vertex)
{
    for (int cur = 1; cur <= n; cur++)
    {
        if (graph[vertex][cur] && !visited[cur])
        {
            ans++;
            visited[cur] = true;
            DFS(cur);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]][to[i]]++;
        graph[to[i]][from[i]]++;
    }

    DFS(1);

    cout << (ans ? ans - 1 : ans);

    return 0;
}

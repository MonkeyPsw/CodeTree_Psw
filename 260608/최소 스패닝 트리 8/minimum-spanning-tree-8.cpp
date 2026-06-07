#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int from[1000], to[1000], weight[1000];

int graph[501][501];
bool visited[501];
int dist[501];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = 1000000000;

        for (int j = 1; j <= n; j++) {
            graph[i][j] = 1000000000;
        }
    }

    for (int i = 0; i < m; i++) {
        int a = from[i];
        int b = to[i];
        int w = weight[i];

        graph[a][b] = min(graph[a][b], w);
        graph[b][a] = min(graph[b][a], w);
    }

    dist[1] = 0;

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int minIdx = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                if (minIdx == -1 || dist[j] < dist[minIdx]) {
                    minIdx = j;
                }
            }
        }

        visited[minIdx] = true;
        answer += dist[minIdx];

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && graph[minIdx][j] < dist[j]) {
                dist[j] = graph[minIdx][j];
            }
        }
    }

    cout << answer;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

const int MAX_N = 500;

int n;
int dist[MAX_N][MAX_N];

bool visited[MAX_N];
int min_dist[MAX_N];
int parent[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        min_dist[i] = 2e9;
        visited[i] = false;
    }

    min_dist[0] = 0;
    parent[0] = -1;

    vector<tuple<int, int, int>> edges;

    for (int step = 0; step < n; step++) {
        int u = -1;
        int best = 2e9;
        
        // 방문하지 않은 노드 중 가장 가까운 노드 선택
        for (int i = 0; i < n; i++) {
            if (!visited[i] && min_dist[i] < best) {
                best = min_dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        // 트리의 간선 추가 (1번 노드부터 시작하도록 +1 처리 및 a < b 조건 충족)
        if (parent[u] != -1) {
            int a = min(parent[u], u) + 1;
            int b = max(parent[u], u) + 1;
            edges.push_back({a, b, dist[parent[u]][u]});
        }

        // 인접한 노드들의 최소 거리 갱신
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u][v] < min_dist[v]) {
                min_dist[v] = dist[u][v];
                parent[v] = u;
            }
        }
    }

    // 정답 출력 형식에 맞게 사전순 정렬 (a 우선, b 차선)
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int a, b, w;
        tie(a, b, w) = edges[i];
        cout << a << " " << b << " " << w << endl;
    }

    return 0;
}
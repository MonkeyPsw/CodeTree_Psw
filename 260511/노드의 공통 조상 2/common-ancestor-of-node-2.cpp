#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 50001;
const int LOG = 17; // 2^16 = 65536 > 50000

int n;
int q;

int from[50000];
int to[50000];

int query_a[10000];
int query_b[10000];

vector<int> graph[MAX];

int depth[MAX];
int parent[MAX][LOG];

void bfs() {
    queue<int> qu;

    qu.push(1);
    depth[1] = 0;
    parent[1][0] = 0;

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for (int next : graph[cur]) {
            if (next == parent[cur][0])
                continue;

            depth[next] = depth[cur] + 1;
            parent[next][0] = cur;

            qu.push(next);
        }
    }
}

void make_parent() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b) {
    // b를 더 깊게 맞춤
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    // 깊이 맞추기
    int diff = depth[b] - depth[a];

    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i)) {
            b = parent[b][i];
        }
    }

    // 이미 같은 노드면 반환
    if (a == b)
        return a;

    // 동시에 올리기
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    bfs();
    make_parent();

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> query_a[i] >> query_b[i];

        cout << lca(query_a[i], query_b[i]) << endl;
    }

    return 0;
}
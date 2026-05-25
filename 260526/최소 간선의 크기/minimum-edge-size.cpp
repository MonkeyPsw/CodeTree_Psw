#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a, b;
int from[100000], to[100000], satisfaction[100000];

int parent[100001];

struct Edge {
    int u;
    int v;
    int w;
};

Edge edges[100000];

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    if (X != Y)
        parent[X] = Y;
}

bool cmp(Edge x, Edge y) {
    return x.w > y.w;
}

int main() {
    cin >> n >> m;
    cin >> a >> b;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> satisfaction[i];
        edges[i].u = from[i];
        edges[i].v = to[i];
        edges[i].w = satisfaction[i];
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 만족도 내림차순 정렬
    sort(edges, edges + m, cmp);

    // 높은 만족도부터 연결
    for (int i = 0; i < m; i++) {
        Union(edges[i].u, edges[i].v);

        if (Find(a) == Find(b)) {
            cout << edges[i].w;
            return 0;
        }
    }

    return 0;
}
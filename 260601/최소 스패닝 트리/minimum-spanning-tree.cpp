#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];

struct Edge {
    int from;
    int to;
    int weight;
};

Edge edges[100000];

int parent[10001];

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

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];

        edges[i].from = from[i];
        edges[i].to = to[i];
        edges[i].weight = weight[i];
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    sort(edges, edges + m, cmp);

    int answer = 0;

    for (int i = 0; i < m; i++) {
        int a = edges[i].from;
        int b = edges[i].to;
        int w = edges[i].weight;

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += w;
        }
    }

    cout << answer << endl;

    return 0;
}
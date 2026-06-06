#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
int from[100000], to[100000], edge_type[100000];

tuple<int, int, int> edges[100000];

int parent[100001];

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

int Kruskal(bool isMax) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        if (isMax) {
            edges[i] = make_tuple(edge_type[i], from[i], to[i]);
        } else {
            edges[i] = make_tuple(1 - edge_type[i], from[i], to[i]);
        }
    }

    sort(edges, edges + m);

    int zeroCnt = 0;
    int edgeCnt = 0;

    for (int i = 0; i < m; i++) {
        int type, a, b;
        tie(type, a, b) = edges[i];

        int realType;

        if (isMax) {
            realType = type;
        } else {
            realType = 1 - type;
        }

        if (Find(a) != Find(b)) {
            Union(a, b);

            if (realType == 0) {
                zeroCnt++;
            }

            edgeCnt++;

            if (edgeCnt == n - 1) {
                break;
            }
        }
    }

    return zeroCnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> edge_type[i];
    }

    int maxZero = Kruskal(true);
    int minZero = Kruskal(false);

    cout << maxZero * maxZero - minZero * minZero;

    return 0;
}
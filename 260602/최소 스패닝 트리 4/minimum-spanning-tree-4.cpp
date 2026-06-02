#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
char type[10000];
int from[100000];
int to[100000];
int weight[100000];

tuple<int, int, int> edges[100000];

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

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> type[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        edges[i] = make_tuple(weight[i], from[i], to[i]);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    sort(edges, edges + m);

    int answer = 0;
    int edgeCnt = 0;

    for (int i = 0; i < m; i++) {
        int w, a, b;
        tie(w, a, b) = edges[i];

        if (type[a - 1] == type[b - 1]) {
            continue;
        }

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += w;
            edgeCnt++;
        }
    }

    if (edgeCnt == n - 1) {
        cout << answer;
    } else {
        cout << -1;
    }

    return 0;
}
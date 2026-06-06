#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
int from[100000];
int to[100000];
int weight[100000];

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

int main() {
    cin >> n >> m;

    int total = 0;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        total += weight[i];
        edges[i] = make_tuple(weight[i], from[i], to[i]);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    sort(edges, edges + m);

    int mst = 0;
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        int w, a, b;
        tie(w, a, b) = edges[i];

        if (Find(a) != Find(b)) {
            Union(a, b);
            mst += w;
            cnt++;

            if (cnt == n - 1)
                break;
        }
    }

    cout << total - mst;

    return 0;
}
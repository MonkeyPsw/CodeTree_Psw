#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
int horizontal[300][300];
int vertical[300][300];

tuple<int, int, int> edges[180000];

int parent[90001];

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

int GetNum(int r, int c) {
    return r * m + c + 1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++) cin >> horizontal[i][j];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++) cin >> vertical[i][j];

    int edgeCnt = 0;

    // 가로 간선
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            int a = GetNum(i, j);
            int b = GetNum(i, j + 1);
            edges[edgeCnt++] = make_tuple(horizontal[i][j], a, b);
        }
    }

    // 세로 간선
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int a = GetNum(i, j);
            int b = GetNum(i + 1, j);
            edges[edgeCnt++] = make_tuple(vertical[i][j], a, b);
        }
    }

    for (int i = 1; i <= n * m; i++) {
        parent[i] = i;
    }

    sort(edges, edges + edgeCnt);

    int answer = 0;

    for (int i = 0; i < edgeCnt; i++) {
        int w, a, b;
        tie(w, a, b) = edges[i];

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += w;
        }
    }

    cout << answer;

    return 0;
}
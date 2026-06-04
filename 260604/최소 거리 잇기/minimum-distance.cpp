#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int x[200], y[200];
int from[200], to[200];

tuple<double, int, int> edges[40000];

int parent[201];

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
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 이미 연결된 간선 처리
    for (int i = 0; i < m; i++) {
        Union(from[i], to[i]);
    }

    int edgeCnt = 0;

    // 모든 점 쌍 간선 생성
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];

            double dist = sqrt(dx * dx + dy * dy);

            edges[edgeCnt++] = make_tuple(dist, i + 1, j + 1);
        }
    }

    sort(edges, edges + edgeCnt);

    double answer = 0;

    for (int i = 0; i < edgeCnt; i++) {
        double dist;
        int a, b;

        tie(dist, a, b) = edges[i];

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += dist;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << answer;

    return 0;
}
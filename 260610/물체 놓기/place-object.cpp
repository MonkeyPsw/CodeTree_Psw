#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
int direct[300];
int cost[300][300];

tuple<int, int, int> edges[100000];

int parent[301];

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
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> direct[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int edgeCnt = 0;

    for (int i = 1; i <= n; i++) {
        edges[edgeCnt++] = make_tuple(direct[i - 1], 0, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[edgeCnt++] = make_tuple(cost[i][j], i + 1, j + 1);
        }
    }

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    sort(edges, edges + edgeCnt);

    int answer = 0;
    int cnt = 0;

    for (int i = 0; i < edgeCnt; i++) {
        int w, a, b;
        tie(w, a, b) = edges[i];

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += w;
            cnt++;

            if (cnt == n)
                break;
        }
    }

    cout << answer;

    return 0;
}
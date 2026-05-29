#include <iostream>

using namespace std;

int n, m;
int from[100000], to[100000];

int parent[200001];

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

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // 초기화
    for (int i = 1; i <= 2 * n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u = from[i];
        int v = to[i];

        // 서로 반대 팀 연결
        Union(u, v + n);
        Union(u + n, v);
    }

    // 모순 검사
    for (int i = 1; i <= n; i++) {
        if (Find(i) == Find(i + n)) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;

    return 0;
}
#include <iostream>

using namespace std;

int n, m, k;
int from[100000], to[100000];
int path[100000];

int parent[100001];

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    parent[X] = Y;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> path[i];
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 모든 간선 연결
    for (int i = 0; i < m; i++) {
        Union(from[i], to[i]);
    }

    // 경로 확인
    for (int i = 0; i < k - 1; i++) {
        if (Find(path[i]) != Find(path[i + 1])) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;

    return 0;
}
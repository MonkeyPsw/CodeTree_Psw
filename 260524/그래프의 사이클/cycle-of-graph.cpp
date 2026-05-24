#include <iostream>

using namespace std;

int n, m;
int from[100000], to[100000];

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

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 간선을 순서대로 추가
    for (int i = 0; i < m; i++) {
        int u = from[i];
        int v = to[i];

        // 이미 같은 집합이면 사이클 발생
        if (Find(u) == Find(v)) {
            cout << i + 1;
            return 0;
        }

        Union(u, v);
    }

    // 끝까지 사이클이 없으면
    cout << "happy";

    return 0;
}
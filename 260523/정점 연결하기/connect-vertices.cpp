#include <iostream>

using namespace std;

int n;
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
    cin >> n;

    for (int i = 0; i < n - 2; i++) {
        cin >> from[i] >> to[i];
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 간선 연결
    for (int i = 0; i < n - 2; i++) {
        Union(from[i], to[i]);
    }

    int root1 = Find(1);
    int a = 1;
    int b = 0;

    // 다른 연결 요소 찾기
    for (int i = 2; i <= n; i++) {
        if (Find(i) != root1) {
            b = i;
            break;
        }
    }

    int root2 = Find(b);

    // 첫 번째 집합의 최소 정점 찾기
    a = n + 1;
    for (int i = 1; i <= n; i++) {
        if (Find(i) == root1 && i < a) {
            a = i;
        }
    }

    // 두 번째 집합의 최소 정점 찾기
    b = n + 1;
    for (int i = 1; i <= n; i++) {
        if (Find(i) == root2 && i < b) {
            b = i;
        }
    }

    cout << a << " " << b;

    return 0;
}
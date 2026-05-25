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

    int removeCnt = 0;

    // 사이클 체크
    for (int i = 0; i < m; i++) {
        int u = from[i];
        int v = to[i];

        if (Find(u) == Find(v)) {
            removeCnt++;
        } else {
            Union(u, v);
        }
    }

    // 연결 요소 개수 세기
    int componentCnt = 0;

    for (int i = 1; i <= n; i++) {
        if (Find(i) == i) {
            componentCnt++;
        }
    }

    // 필요한 최소 연산 수
    int answer = removeCnt + (componentCnt - 1);

    cout << answer;

    return 0;
}
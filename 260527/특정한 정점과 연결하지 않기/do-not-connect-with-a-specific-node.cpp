#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int from[100000], to[100000];
int A, B, k;

int parent[100001];
int sz[100001];
int compSize[100000];

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    if (X == Y)
        return;

    parent[X] = Y;
    sz[Y] += sz[X];
}

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    cin >> A >> B >> k;

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    // 기존 간선들 연결
    for (int i = 0; i < m; i++) {
        Union(from[i], to[i]);
    }

    int rootA = Find(A);
    int rootB = Find(B);

    int answer = sz[rootA];
    int cnt = 0;

    // A, B가 아닌 다른 연결 요소들의 크기 저장
    for (int i = 1; i <= n; i++) {
        if (Find(i) == i) {
            if (i == rootA || i == rootB)
                continue;

            compSize[cnt++] = sz[i];
        }
    }

    // 큰 것부터 정렬
    sort(compSize, compSize + cnt, cmp);

    // 최대 k개 선택
    for (int i = 0; i < cnt && i < k; i++) {
        answer += compSize[i];
    }

    cout << answer;

    return 0;
}
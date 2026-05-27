#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int vertex[100001];
int from[100000], to[100000];

int parent[100001];
int minValue[100001];

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

    // 연결 요소 최소값 갱신
    minValue[Y] = min(minValue[Y], minValue[X]);
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> vertex[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        minValue[i] = vertex[i];
    }

    // 기존 간선 연결
    for (int i = 0; i < m; i++) {
        Union(from[i], to[i]);
    }

    long long sum = 0;
    int globalMin = 1000000000;
    int componentCnt = 0;

    // 각 연결 요소의 최소값 수집
    for (int i = 1; i <= n; i++) {
        if (Find(i) == i) {
            componentCnt++;

            sum += minValue[i];
            globalMin = min(globalMin, minValue[i]);
        }
    }

    // 이미 모두 연결됨
    if (componentCnt == 1) {
        cout << 0;
        return 0;
    }

    // 최소 비용 계산
    long long answer =
        sum + 1LL * globalMin * (componentCnt - 2);

    if (answer > k) {
        cout << "NO";
    } else {
        cout << answer;
    }

    return 0;
}
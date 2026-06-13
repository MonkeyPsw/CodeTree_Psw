#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int cost[200001];
int a[200000], b[200000];

int parent[200001];
bool blocked[200001];
int minCost[200001];

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
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        minCost[i] = 1000000001;
    }

    for (int i = 0; i < m; i++) {
        int x = a[i];
        int y = b[i];

        if (x > y)
            swap(x, y);

        if (x == 1 && y == n)
            blocked[n] = true;
        else
            blocked[x] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (blocked[i])
            continue;

        int next = i + 1;
        if (next == n + 1)
            next = 1;

        Union(i, next);
    }

    int compCnt = 0;

    for (int i = 1; i <= n; i++) {
        int root = Find(i);
        minCost[root] = min(minCost[root], cost[i]);
    }

    long long total = 0;

    for (int i = 1; i <= n; i++) {
        if (Find(i) == i) {
            compCnt++;
            total += minCost[i];
        }
    }

    if (compCnt == 1) {
        cout << 1;
    }
    else if (total <= k) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
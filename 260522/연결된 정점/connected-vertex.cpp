#include <iostream>

using namespace std;

int n, m;
char op;
int a, b;

int parent[100001];
int sz[100001];

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

int main() {
    cin >> n >> m;

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> op;

        if (op == 'x') {
            cin >> a >> b;
            Union(a, b);
        }
        else {
            cin >> a;
            cout << sz[Find(a)] << endl;
        }
    }

    return 0;
}
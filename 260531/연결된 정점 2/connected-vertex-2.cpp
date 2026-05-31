#include <iostream>

using namespace std;

int n;
int a[100000], b[100000];

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
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= 100000; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        Union(a[i], b[i]);

        cout << sz[Find(a[i])] << endl;
    }

    return 0;
}
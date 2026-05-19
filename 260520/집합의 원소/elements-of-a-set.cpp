#include <iostream>

using namespace std;

int n, m;
int query[100000][3];

int parent[100001];

int Find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);

    if (pa != pb)
        parent[pb] = pa;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int type = query[i][0];
        int a = query[i][1];
        int b = query[i][2];

        if (type == 0) {
            Union(a, b);
        }
        else {
            if (Find(a) == Find(b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}
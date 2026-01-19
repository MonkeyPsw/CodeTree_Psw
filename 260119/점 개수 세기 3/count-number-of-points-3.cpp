#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int n, q;
int points[MAX_N];
int a[MAX_N], b[MAX_N];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points, points + n);

    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < q; i++)
    {
        int cnt = upper_bound(points, points + n, b[i])
                - lower_bound(points, points + n, a[i]);

        cout << cnt << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
int points[100000];
int a[100000], b[100000];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
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
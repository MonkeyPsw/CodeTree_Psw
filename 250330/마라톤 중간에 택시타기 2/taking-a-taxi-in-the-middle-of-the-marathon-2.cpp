#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int n;
int x[100];
int y[100];
int length;
int ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n - 1; i++)
        length += abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);

    for (int i = 1; i < n - 1; i++)
    {
        int cnt = length;
        cnt -= abs(x[i - 1] - x[i]) + abs(y[i - 1] - y[i]);
        cnt -= abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        cnt += abs(x[i - 1] - x[i + 1]) + abs(y[i - 1] - y[i + 1]);

        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}
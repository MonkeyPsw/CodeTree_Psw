#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int a[1003];
int ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += a[(i + j) % n] * j;
        
        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int h[100];
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i < 1000; i++)
    {
        int cnt = 0;

        for (int j = 0; j < n - 1; j++)
        {
            if (h[j] - i && !(h[j + 1] - i))
                cnt++;
        }

        if (h[n - 1] - i && !(h[n - 2] - i))
            cnt++;

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
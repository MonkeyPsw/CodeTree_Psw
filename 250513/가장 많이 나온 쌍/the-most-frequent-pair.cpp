#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[100], b[100];
int ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int cnt = 0;

            for (int k = 0; k < m; k++)
            {
                if (i == a[k] && j == b[k] ||
                    j == a[k] && i == b[k])
                    cnt++;
            }
            
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}
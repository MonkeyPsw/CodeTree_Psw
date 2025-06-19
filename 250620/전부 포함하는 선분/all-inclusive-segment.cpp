#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1[100], x2[100];
int ans = 100;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n; i++)
    {
        int start = 100, end = 0;

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                start = min(start, x1[j]);
                end = max(end, x2[j]);
            }
        }

        int cnt = end - start;
        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}
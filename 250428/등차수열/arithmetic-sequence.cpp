#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int a[100];
int arr[100];
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 공차를 기준으로 for문을 돌리면 되는구나
    for (int k = 1; k <= 100; k++)
    {
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] + a[j] == k * 2)
                    cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    /*
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) % 2 == 0)
            {
                int k = (a[i] + a[j]) / 2;
                arr[k]++;
            }
        }
    }

    for (int i = 2; i < 100; i++)
        ans = max(ans, arr[i]);
    
    cout << ans;
    */

    return 0;
}

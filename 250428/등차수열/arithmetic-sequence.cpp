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

    return 0;
}

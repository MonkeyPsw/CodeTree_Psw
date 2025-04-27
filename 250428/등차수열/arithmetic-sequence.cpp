#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int a[100];
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(a[i] - a[j]) <= 1)
                continue;

            for (int k = min(a[i], a[j]) + 1; k <= max(a[i], a[j]) - 1; k++)
            {
                if (a[j] - k == k - a[i])
                    ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}
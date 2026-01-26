#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int maxL[100000], maxR[100000];
int curMax, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    curMax = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curMax)
            curMax = arr[i];

        maxL[i] = curMax;
    }

    curMax = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > curMax)
            curMax = arr[i];
        
        maxR[i] = curMax;
    }

    for (int i = 2; i < n - 2; i++)
        ans = max(ans, arr[i - 2] + arr[i] + arr[i + 2]);

    cout << ans;

    return 0;
}

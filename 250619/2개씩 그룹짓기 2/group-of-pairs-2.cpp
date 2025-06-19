#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[200000];
int ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 2 * n);

    for (int i = 0; i < n; i++)
    {
        int cnt = arr[i + n] - arr[i];

        ans = min(ans, cnt);
    }
    
    cout << ans;

    return 0;
}
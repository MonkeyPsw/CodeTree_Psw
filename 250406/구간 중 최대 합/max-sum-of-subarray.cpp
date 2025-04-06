#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, k;
int arr[100];
int ans = INT_MIN;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = i; j < i + k; j++)
            sum += arr[j];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
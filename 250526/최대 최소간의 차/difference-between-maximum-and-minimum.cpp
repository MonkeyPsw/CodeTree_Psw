#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[100];
int ans = INT_MAX;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= 10000; i++)
    {
        int cnt = 0;
        
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < i)
                cnt += i - arr[j];
            else if (arr[j] > i + k)
                cnt += arr[j] - (i + k);
        }

        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}
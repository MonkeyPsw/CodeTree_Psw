#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[1000000];
int cnt, j;
int ans = INT_MAX;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (j < n && cnt < k)
        {
            if (arr[j] == 1)
                cnt++;
            
            j++;
        }

        if (cnt >= k)
            ans = min(ans, j - i);

        if (arr[i] == 1)
            cnt--;
    }
    
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[1000];
int dp[1000];
int ans;

void Init()
{
    for (int i = 0; i < n; i++)
        dp[i] = INT_MIN;
        
    dp[0] = 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Init();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] == INT_MIN)
                continue;
            
            if (j + arr[j] >= i)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    
    cout << ans;

    return 0;
}
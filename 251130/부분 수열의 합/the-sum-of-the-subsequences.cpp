#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int A[100];
int dp[10001];
int ans;

void Init()
{
    for (int i = 0; i <= m; i++)
        dp[i] = INT_MAX;
    
    dp[0] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Init();

    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j >= A[i])
            {
                if (dp[j - A[i]] == INT_MAX)
                    continue;
                
                dp[j] = min(dp[j], dp[j - A[i]] + 1);
            }
        }
    }

    cout << (dp[m] == INT_MAX ? "No" : "Yes");

    return 0;
}

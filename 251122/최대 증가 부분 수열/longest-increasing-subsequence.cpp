#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int M[1000];
int dp[1000];
int ans;

void Init()
{
    for (int i = 0; i < N; i++)
        dp[i] = 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    Init();

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] == INT_MIN)
                continue;
            
            if (M[i] > M[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);
    
    cout << ans;

    return 0;
}

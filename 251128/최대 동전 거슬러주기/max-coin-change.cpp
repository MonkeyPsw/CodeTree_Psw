#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int coin[101];
int dp[10001];
int ans;

void Init()
{
    for (int i = 1; i <= M; i++)
        dp[i] = INT_MIN;
    
    dp[0] = 0;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    Init();

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i >= coin[j])
            {
                if (dp[i - coin[j]] == INT_MIN)
                    continue;
                
                dp[i] = max(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    cout << (dp[M] == INT_MIN ? -1 : dp[M]);

    return 0;
}
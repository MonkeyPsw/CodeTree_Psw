#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int val[3] = {1, 2, 5};
int dp[1001];

int main() {
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i >= val[j])
                dp[i] = (dp[i] + dp[i - val[j]]) % 10007;
        }
    }

    cout << dp[n];

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[501][501];
int preSum[501][501];
int ans;

bool InRange(int x, int y)
{
    return x >= 0 && y >= 0;
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            preSum[i][j] = preSum[i - 1][j] +
                           preSum[i][j - 1] -
                           preSum[i - 1][j - 1] +
                           arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (InRange(i - k, j - k))
                ans = max(ans, preSum[i][j] - preSum[i - k][j] - preSum[i][j - k] + preSum[i - k][j - k]);
        }
    }

    cout << ans;

    return 0;
}

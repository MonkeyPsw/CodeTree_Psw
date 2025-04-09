#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, K;
int candy[100], pos[100];
int arr[101][101];
int ans = INT_MIN;

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> candy[i] >> pos[i];

        for (int j = 0; j <= N; j++)
        {
            if (!arr[pos[i]][j])
            {
                arr[pos[i]][j] = candy[i];
                break;
            }
        }
    }

    for (int i = K; i < 100 - K; i++)
    {
        int sum = 0;

        for (int j = i - K; j <= i + K; j++)
        {
            for (int l = 0; l <= N; l++)
            {
                if (arr[j][l])
                    sum += arr[j][l];
                else
                    break;
            }
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
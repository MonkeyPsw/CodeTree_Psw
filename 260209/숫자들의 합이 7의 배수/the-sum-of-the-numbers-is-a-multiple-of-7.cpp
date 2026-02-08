#include <iostream>
#include <algorithm>

using namespace std;

int N;
int numbers[50000];
int preSum[50000];
int idx[7];
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 1; i < 7; i++)
        idx[i] = -1;

    preSum[0] = numbers[0] % 7;
    for (int i = 1; i < N; i++)
        preSum[i] = (preSum[i - 1] + numbers[i]) % 7;

    for (int i = 0; i < N; i++)
    {
        if (idx[preSum[i]] == -1)
            idx[preSum[i]] = i;
        else
        {
            if (preSum[i] == 0)
                ans = max(ans, i - idx[preSum[i]] + 1);
            else
                ans = max(ans, i - idx[preSum[i]]);
        }
    }

    cout << ans;

    return 0;
}
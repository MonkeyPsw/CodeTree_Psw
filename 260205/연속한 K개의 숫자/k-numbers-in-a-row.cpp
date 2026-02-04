#include <iostream>
#include <algorithm>

using namespace std;

int N, K, B;
int missing[100001];
int preSum[100001];
int ans = 100000;

int main() {
    cin >> N >> K >> B;

    for (int i = 0; i < B; i++)
    {
        int x;
        cin >> x;

        missing[x] = 1;
    }

    for (int i = 1; i <= N; i++)
        preSum[i] = preSum[i - 1] + missing[i];
    
    for (int i = 1; i + K - 1 <= N; i++)
        ans = min(ans, preSum[i + K - 1] - preSum[i - 1]);

    cout << ans;

    return 0;
}

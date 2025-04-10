#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int N, H, T;
int arr[100];
int ans = INT_MAX;

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= N - T; i++)
    {
        int sum = 0;

        for (int j = i; j < i + T; j++)
            sum += abs(H - arr[j]);

        ans = min(ans, sum);
    }
    
    cout << ans;

    return 0;
}
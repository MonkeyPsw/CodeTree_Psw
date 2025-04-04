#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int N, S;
int arr[100];
int sum;
int ans = INT_MAX;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int cnt = sum - arr[i] - arr[j];
            ans = min(ans, abs(cnt - S));
        }
    }

    cout << ans;

    return 0;
}
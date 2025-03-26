#include <iostream>
#include <climits>

using namespace std;

int n;
int A[100];
int ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        for (int j = 0; j < n; j++)
            cnt += abs(i - j) * A[j];

        if (ans > cnt)
            ans = cnt;
    }

    cout << ans;

    return 0;
}
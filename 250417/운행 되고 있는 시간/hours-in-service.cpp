#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[100], B[100];
int ans = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        
    }

    for (int i = 0; i < N; i++)
    {
        int work[1001] = {};

        for (int j = 0; j < N; j++)
        {
            if (j == i)
                continue;

            for (int k = A[j]; k < B[j]; k++)
                work[k]++;
        }

        int cnt = 0;

        for (int j = 1; j <= 1000; j++)
        {
            if (work[j])
                cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
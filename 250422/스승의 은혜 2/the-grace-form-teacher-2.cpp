#include <iostream>
#include <algorithm>

using namespace std;

int N, B;
int P[1000];
int ans = 0;

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int cnt = N;

        P[i] /= 2;

        for (int j = 0; j < N; j++)
            sum += P[j];

        for (int j = N - 1; j >= 0; j--)
        {
            if (sum > B)
            {
                sum -= P[j];
                cnt--;
            }
            else
                break;
        }

        ans = max(ans, cnt);

        P[i] *= 2;
    }

    cout << ans;

    return 0;
}
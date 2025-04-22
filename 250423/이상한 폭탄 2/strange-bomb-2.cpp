#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int num[100];
int ans = -1;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (num[i] == num[j] && (j - i) <= K)
                ans = max(ans, num[i]);
        }
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, K;
int x[100];
char c[100];
char line[10001];
int ans = INT_MIN;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> c[i];

        line[x[i]] = c[i];
    }

    for (int i = 1; i <= N - K + 1; i++)
    {
        int cnt = 0;
        
        for (int j = i; j <= i + K; j++)
        {
            if (line[j] == 'G')
                cnt++;
            else if (line[j] == 'H')
                cnt += 2;
        }
        
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
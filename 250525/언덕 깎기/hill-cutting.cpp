#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int heights[1000];
int ans = INT_MAX;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i <= 100; i++)
    {
        int cnt = 0;
        
        for (int j = 0; j < N; j++)
        {
            if (heights[j] < i)
                cnt += (i - heights[j]) * (i - heights[j]);
            else if (heights[j] > i + 17)
                cnt += (heights[j] - (i + 17)) * (heights[j] - (i + 17));
        }

        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}
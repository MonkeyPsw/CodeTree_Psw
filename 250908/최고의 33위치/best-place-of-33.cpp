#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int grid[20][20];
int ans = INT_MIN;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int x = 0; x < N - 2; x++)
    {
        int cnt = 0;

        for (int i = x; i <= x + 2; i++)
        {
            for (int j = x; j <= x + 2; j++)
            {
                if (grid[i][j])
                    cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}

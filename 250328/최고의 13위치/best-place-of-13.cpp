#include <iostream>
#include <climits>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 2; j++)
            ans = max(ans, grid[i][j] + grid[i][j + 1] + grid[i][j + 2]);
    }
    
    cout << ans;

    return 0;
}
#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y, int n)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int x = 0; x < n; x++)
    {    
        for (int y = 0; y < n; y++)
        {
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (InRange(nx, ny, n) && grid[nx][ny])
                    cnt++;
            }

            if (cnt >= 3)
                ans++;
        }
    }
    
    cout << ans;

    return 0;
}
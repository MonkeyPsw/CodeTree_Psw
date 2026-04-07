#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ans;

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y])
        return false;
    
    return true;
}

void Reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    }
}

bool DFS(int x, int y, int D, int num)
{
    if (x == n - 1 && y == m - 1)
        return true;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (CanGo(nx, ny) && board[nx][ny] >= num && board[nx][ny] <= num + D)
        {
            if (DFS(nx, ny, D, num))
                return true;
        }
    }

    return false;
}

bool IsPossible(int D)
{
    int maxH = min(board[0][0], board[n - 1][m - 1]);
    int minH = max(board[0][0] - D, board[n - 1][m - 1] - D);

    if (maxH < minH)
        return false;

    for (int i = minH; i <= maxH; i++)
    {
        Reset();

        if (DFS(0, 0, D, i))
            return true;
    }
    
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int left = 0;
    int right = 500;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}

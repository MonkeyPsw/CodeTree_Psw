#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int visited[100][100];
int dx[2] = {1, 0}, dy[2] = {0, 1};

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y] || !grid[x][y])
        return false;
    
    return true;
}

void DFS(int x, int y)
{
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (CanGo(nx, ny))
        {
            visited[nx][ny] = 1;
            DFS(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = 1;
    DFS(0, 0);

    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << visited[i][j];
        cout << endl;
    }
    */

    cout << (visited[0][0] && visited[n - 1][m - 1] ? 1 : 0);

    return 0;
}

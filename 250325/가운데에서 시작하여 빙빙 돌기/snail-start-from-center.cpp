#include <iostream>

using namespace std;

int n;
int grid[100][100];
int x, y;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int d = 2;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin >> n;

    x = n - 1;
    y = n - 1;

    grid[x][y] = n * n;

    for (int i = n * n - 1; i >= 1; i--)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (!InRange(nx, ny) || grid[nx][ny])
            d = (d + 1) % 4;

        x += dx[d];
        y += dy[d];
        grid[x][y] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}
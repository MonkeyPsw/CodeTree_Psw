#include <iostream>

using namespace std;

int n, m;
int arr[100][100];
int x, y;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int d;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    cin >> n >> m;

    arr[x][y] = 1;

    for (int i = 2; i <= n * m; i++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (!InRange(nx, ny) || arr[nx][ny])
            d = (d + 1) % 4;

        x += dx[d];
        y += dy[d];
        arr[x][y] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}
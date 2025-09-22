#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[20][20];
// 위부터 시계방향
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool InRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    while (m--)
    {

        for (int i = 1; i <= n * n; i++)
        {
            int curX = 0, curY = 0;

            for (int j = 0; j < n; j++)
            {
                if (!curX)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (i == grid[j][k])
                        {
                            curX = j;
                            curY = k;
                            break;
                        }
                    }
                }
            }

            int maxNum = 0;
            int maxX = 0, maxY = 0;

            for (int j = 0; j < 8; j++)
            {
                int nx = curX + dx[j];
                int ny = curY + dy[j];

                if (InRange(nx, ny) && grid[nx][ny] > maxNum)
                {
                    maxNum = grid[nx][ny];
                    maxX = nx;
                    maxY = ny;
                }
            }

            swap(grid[curX][curY], grid[maxX][maxY]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}

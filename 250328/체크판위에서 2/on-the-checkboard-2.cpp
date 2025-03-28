#include <iostream>

using namespace std;

int R, C;
char grid[15][15];
int cnt;

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == 'W' && grid[R - 1][C - 1] == 'B')
    {
        for (int i = 1; i < R - 1; i++)
        {
            for (int j = 1; j < C - 1; j++)
            {
                if (grid[i][j] == 'B')
                {
                    for (int k = i + 1; k < R - 1; k++)
                    {
                        for (int l = j + 1; l < C - 1; l++)
                        {
                            if (grid[k][l] == 'W')
                                cnt++;
                        }
                    }
                }
            }
        }
    }

    if (grid[0][0] == 'B' && grid[R - 1][C - 1] == 'W')
    {
        for (int i = 1; i < R - 1; i++)
        {
            for (int j = 1; j < C - 1; j++)
            {
                if (grid[i][j] == 'W')
                {
                    for (int k = i + 1; k < R - 1; k++)
                    {
                        for (int l = j + 1; l < C - 1; l++)
                        {
                            if (grid[k][l] == 'B')
                                cnt++;
                        }
                    }
                }
            }
        }
    }

    /* 이게 더 쉽네
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            for(int k = i + 1; k < n - 1; k++)
                for(int l = j + 1; l < m - 1; l++)
                    // 그 중 색깔이 전부 달라지는 경우에만 개수를 세줍니다.
                    if(grid[0][0] != grid[i][j] && 
                       grid[i][j] != grid[k][l] &&
                       grid[k][l] != grid[n - 1][m - 1])
                        cnt++;
    */

    cout << cnt;

    return 0;
}
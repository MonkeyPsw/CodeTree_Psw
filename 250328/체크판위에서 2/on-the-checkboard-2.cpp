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

    cout << cnt;

    return 0;
}
#include <iostream>

using namespace std;

int T;
int N, M;
int x[2500];
int y[2500];
char d[2500];
int grid[50][50];
// 상좌우하 3-dir
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool InRange(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int GetDir(char dir)
{
    if (dir == 'U')
        return 0;
    else if (dir == 'L')
        return 1;
    else if (dir == 'R')
        return 2;
    else
        return 3;
}

void ResetGrid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            grid[i][j] = -1;
    }
}

void SetGrid(int x, int y, char c)
{
    int curX = x - 1, curY = y - 1;
    int dir = GetDir(c);

    grid[curX][curY] = dir;
}

int CheckGrid()
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] >= 0)
                cnt++;
        }
    }

    return cnt;
}

void MoveOrb()
{
    int orbCnt[50][50] = {};
    int tmpGrid[50][50] = {};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            tmpGrid[i][j] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] >= 0)
            {
                int nx = i + dx[grid[i][j]];
                int ny = j + dy[grid[i][j]];

                if (InRange(nx, ny))
                {
                    tmpGrid[nx][ny] = grid[i][j];
                    orbCnt[nx][ny]++;
                }
                else
                {
                    tmpGrid[i][j] = 3 - grid[i][j];
                    orbCnt[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (orbCnt[i][j] >= 2)
                tmpGrid[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            grid[i][j] = tmpGrid[i][j];
    }
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;

        ResetGrid();
        
        for (int i = 0; i < M; i++)
        {
            cin >> x[i] >> y[i] >> d[i];

            SetGrid(x[i], y[i], d[i]);
        }

        for (int i = 0; i < 2 * N; i++)
            MoveOrb();
        
        cout << CheckGrid() << endl;
    }

    return 0;
}

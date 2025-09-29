#include <iostream>
#include <cmath>

using namespace std;

int n, m, r, c;
int bombGrid[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void Bomb(int x, int y, int time)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i] * pow(2, time - 1);
        int ny = y + dy[i] * pow(2, time - 1);

        if (InRange(nx, ny) && !bombGrid[nx][ny] && bombGrid[x][y] <= time)
            bombGrid[nx][ny] = time + 1;
    }
}

void SearchBomb(int time)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bombGrid[i][j] > 0)
                Bomb(i, j, time);
        }
    }
}

int CalBomb()
{
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bombGrid[i][j] > 0)
                cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m >> r >> c;

    r--;
    c--;

    bombGrid[r][c] = 1;

    for (int t = 1; t <= m; t++)
        SearchBomb(t);

    cout << CalBomb();

    return 0;
}

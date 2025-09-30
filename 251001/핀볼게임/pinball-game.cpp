#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
// 우하좌상
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int tmp1, tmp2;

bool InRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int NextDir(int curDir, int wall)
{
    if (wall == 1)
    {
        if (curDir % 2 == 0)
            return (curDir + 3) % 4;
        else
            return (curDir + 1) % 4;
    }
    else if (wall == 2)
    {
        if (curDir % 2 == 0)
            return (curDir + 1) % 4;
        else
            return (curDir + 3) % 4;
    }

    return curDir;
}

int Pinball(int x, int y, int startDir)
{
    int cnt = 1;
    int curX = x, curY = y;
    int dir = startDir;

    while (InRange(curX, curY))
    {
        dir = NextDir(dir, grid[curX][curY]);

        int nx = curX + dx[dir];
        int ny = curY + dy[dir];

        cnt++;

        curX = nx;
        curY = ny;
    }

    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < n; i++)
    {
        tmp1 = max(Pinball(0, i, 1), Pinball(i, 0, 0));
        tmp2 = max(Pinball(n - 1, i, 3), Pinball(i, n - 1, 2));
    }

    cout << max(tmp1, tmp2);

    return 0;
}

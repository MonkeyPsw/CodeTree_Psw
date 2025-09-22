#include <iostream>
#include <algorithm>

using namespace std;

int n, m, t;
int a[21][21];
int r[400], c[400];
int marble[21][21], tmpMarble[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;

bool InRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void NextMarbleCnt(int x, int y)
{
    int maxNum = 0;
    int curX = x;
    int curY = y;
    int maxX = 0, maxY = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = curX + dx[i];
        int ny = curY + dy[i];

        if (InRange(nx, ny) && a[nx][ny] > maxNum)
        {
            maxNum = a[nx][ny];
            maxX = nx;
            maxY = ny;
        }
    }

    tmpMarble[maxX][maxY]++;
}

void TmpToMarble()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            marble[i][j] = tmpMarble[i][j];
            tmpMarble[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (marble[i][j] >= 2)
                marble[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];

        marble[--r[i]][--c[i]]++;
    }

    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (marble[i][j])
                    NextMarbleCnt(i, j);
            }
        }

        TmpToMarble();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (marble[i][j])
                ans++;
        }
    }

    cout << ans;

    return 0;
}

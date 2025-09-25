#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
// 우하좌상
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y, int x1, int y1, int x2, int y2)
{
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}

void Wind(int x1, int y1, int x2, int y2)
{
    // GPT쿤이 함수 시작에서 0-based로 변환하는게 낫단다
    x1--, y1--, x2--, y2--;

    int tmp[400] = {};
    int length = (x2 - x1 + y2 - y1) * 2;
    int dir = 0;
    int curX = x1, curY = y1;

    for (int i = 0; i < length; i++)
    {
        tmp[i] = a[curX][curY];
        curX += dx[dir];
        curY += dy[dir];

        if (!InRange(curX, curY, x1, y1, x2, y2))
        {
            curX -= dx[dir];
            curY -= dy[dir];
            dir++;
            curX += dx[dir];
            curY += dy[dir];
        }
    }

    dir = 0;
    curX = x1, curY = y1 + 1;

    for (int i = 0; i < length; i++)
    {
        a[curX][curY] = tmp[i];
        curX += dx[dir];
        curY += dy[dir];

        if (!InRange(curX, curY, x1, y1, x2, y2))
        {
            curX -= dx[dir];
            curY -= dy[dir];
            dir++;
            curX += dx[dir];
            curY += dy[dir];
        }
    }
}

void AfterWind(int x1, int y1, int x2, int y2)
{
    x1--, y1--, x2--, y2--;

    int tmpA[100][100] = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            tmpA[i][j] = a[i][j];
    }

    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            int sum = 0, cnt = 1;

            sum += a[i][j];

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (InRange(nx, ny, 0, 0, n - 1, m - 1))
                {
                    cnt++;
                    sum += a[nx][ny];
                }
            }

            tmpA[i][j] = sum / cnt;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            a[i][j] = tmpA[i][j];
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        Wind(r1, c1, r2, c2);
        AfterWind(r1, c1, r2, c2);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}

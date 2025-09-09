#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];
int ans;

// 우, 하, 좌, 상
int dxLine[4] = {0, 1, 0, -1};
int dyLine[4] = {1, 0, -1, 0};

// 우하, 하좌, 좌상, 상우
int dxCurve[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int dyCurve[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

/* dx dy 테크닉 괜히 어려워보여서 고민했던 흔적
bool lineRange[4], curveRange[4];

void CheckRangeLine(int x, int y)
{
    if (x - 2 < 0)
    {
        lineRange[2] = true;
        lineRange[3] = true;
    }

    if (y - 2 < 0)
    {
        lineRange[1] = true;
        lineRange[2] = true;
    }

    if (x + 2 > n - 1)
    {
        lineRange[0] = true;
        lineRange[1] = true;
    }

    if (y + 2 > m - 1)
    {
        lineRange[0] = true;
        lineRange[3] = true;
    }
}

void CheckRangeCurve(int x, int y)
{

}

void RangeReset()
{
    for (int i = 0; i < 4; i++)
    {
        lineRange[i] = false;
        curveRange[i] = false;
    }
}
*/

int LineBlockSum(int x, int y)
{
    int sum = 0;

    /*
    int sum[4] = {};

    for (int i = 0; i <= 2; i++)
    {
        sum[0] += grid[x][y + i];
        sum[1] += grid[x + i][y];
        sum[2] += grid[x][y - i];
        sum[3] += grid[x - i][y];
    }

    for (int i = 0; i < 4; i++)
        cnt = max(cnt, sum[i]);
    */

    for (int i = 0; i < 4; i++)
    {
        bool inRange = true;
        int cnt = 0;

        cnt += grid[x][y];

        for (int j = 1; j <= 2; j++)
        {
            int nx = x + dxLine[i] * j;
            int ny = y + dyLine[i] * j;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                inRange = false;
                break;
            }

            cnt += grid[nx][ny];
        }
        
        if (inRange)
            sum = max(sum, cnt);
    }

    return sum;
}

int CurveBlockSum(int x, int y)
{
    int sum = 0;

    /*
    for (int i = 0; i < 4; i++)
    {
        if (!lineRange[i])
            sum[i] += grid[x][y];
    }

    sum[0] += grid[x][y + 1] + grid[x + 1][y];
    sum[1] += grid[x + 1][y] + grid[x][y - 1];
    sum[2] += grid[x][y - 1] + grid[x - 1][y];
    sum[3] += grid[x - 1][y] + grid[x][y + 1];

    for (int i = 0; i < 4; i++)
        cnt = max(cnt, sum[i]);
    */

    for (int i = 0; i < 4; i++)
    {
        bool inRange = true;
        int cnt = 0;

        cnt += grid[x][y];

        for (int j = 0; j < 2; j++)
        {
            int nx = x + dxCurve[i][j];
            int ny = y + dyCurve[i][j];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                inRange = false;
                break;
            }

            cnt += grid[nx][ny];
        }

        if (inRange)
            sum = max(sum, cnt);
    }
    
    return sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = max(LineBlockSum(i, j), CurveBlockSum(i, j));
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}

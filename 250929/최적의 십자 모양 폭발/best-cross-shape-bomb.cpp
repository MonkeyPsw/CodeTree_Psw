#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[50][50];
int tmpGrid[50][50];
int ans;

void CopyGrid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            tmpGrid[i][j] = grid[i][j];
    }
}

void Bomb(int x, int y)
{
    int size = grid[x][y] - 1;

    CopyGrid();

    for (int i = x - size; i <= x + size; i++)
    {
        if (i >= 0 && i < n)
            tmpGrid[i][y] = 0;
    }

    for (int i = y - size; i <= y + size; i++)
    {
        if (i >= 0 && i < n)
            tmpGrid[x][i] = 0;
    }
}

void arrToGrid(int y)
{
    int tmpArr[50] = {};
    int cnt = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (tmpGrid[i][y])
            tmpArr[cnt++] = tmpGrid[i][y];
    }

    for (int i = cnt; i < n; i++)
        tmpArr[i] = 0;

    for (int i = n - 1; i >= 0; i--)
        tmpGrid[i][y] = tmpArr[n - 1 - i];
}

// 정확히 2개의 칸 이라는 말을 잘못 이해해서 멀리 돌아왔다
int CheckBest()
{
    int cnt = 0;

    // 행에서 쌍 확인
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tmpGrid[i][j] && tmpGrid[i][j] == tmpGrid[i][j + 1])
                cnt++;
        }
    }

    // 열에서 쌍 확인
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmpGrid[i][j] && tmpGrid[i][j] == tmpGrid[i + 1][j])
                cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Bomb(i, j);

            for (int k = 0; k < n; k++)
                arrToGrid(k);
            
            ans = max(ans, CheckBest());
        }
    }

    cout << ans;

    return 0;
}

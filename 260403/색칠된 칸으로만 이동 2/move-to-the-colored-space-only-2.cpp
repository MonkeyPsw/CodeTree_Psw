#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int M, N;
int board[100][100];
int colored[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int cnt, colorCnt, ans;
int a, b;

bool InRange(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y])
        return false;
    
    return true;
}

void Reset()
{
    cnt = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
    }
}

void DFS(int x, int y, int D)
{
    visited[x][y] = true;

    if (colored[x][y] == 1)
        cnt++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (CanGo(nx, ny) && abs(board[x][y] - board[nx][ny]) <= D)
            DFS(nx, ny, D);
    }
}

bool IsPossible(int D)
{
    Reset();

    DFS(a, b, D);

    if (cnt == colorCnt)
        return true;
    
    return false;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> colored[i][j];

            if (colored[i][j] == 1)
            {
                a = i;
                b = j;
                colorCnt++;
            }
        }
    }

    int left = 0;
    int right = 1000000000;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}

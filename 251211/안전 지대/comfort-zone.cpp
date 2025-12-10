#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int grid[50][50];
int visited[50][50];
int visitedCnt;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int maxK, BestK, maxComfortZoneCnt;

bool InRange(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool CanGo(int x, int y, int k)
{
    if (!InRange(x, y))
        return false;
    if (grid[x][y] <= k)
        return false;
    if (visited[x][y] == visitedCnt)
        return false;
    
    return true;
}

void DFS(int x, int y, int k)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (CanGo(nx, ny, k))
        {
            visited[nx][ny] = visitedCnt;
            DFS(nx, ny, k);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            maxK = max(grid[i][j], maxK);
        }
    }

    for (int k = 1; k <= maxK; k++)
    {
        int tmp = 0;

        visitedCnt++;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {

                if (CanGo(i, j, k))
                {
                    visited[i][j] = visitedCnt;
                    DFS(i, j, k);
                    tmp++;
                }
            }
        }

        if (tmp > maxComfortZoneCnt)
        {
            maxComfortZoneCnt = tmp;
            BestK = k;
        }

    }

    cout << BestK << " " << maxComfortZoneCnt;

    return 0;
}

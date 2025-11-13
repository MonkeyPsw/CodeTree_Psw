#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
int visited[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int ans;

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y] || grid[x][y])
        return false;
    
    return true;
}

void Push(int x, int y)
{
    visited[x][y]++;
    q.push(make_pair(x, y));
}

void BFS()
{
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (CanGo(nx, ny))
                Push(nx, ny);
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    for (int i = 0; i < k; i++)
    {
        Push(r[i] - 1, c[i] - 1);
        BFS();
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j])
                ans++;
        }
    }

    cout << ans;

    return 0;
}

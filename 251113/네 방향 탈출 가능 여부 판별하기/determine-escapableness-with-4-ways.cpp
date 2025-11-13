#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
int visited[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y] || !a[x][y])
        return false;
    
    return true;
}

void Push(int x, int y)
{
    visited[x][y] = true;
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
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    Push(0, 0);
    BFS();

    cout << visited[n - 1][m - 1];

    return 0;
}
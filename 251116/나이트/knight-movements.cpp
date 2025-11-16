#include <iostream>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;
bool visited[100][100];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int>> q;
int step[100][100];

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y] || step[x][y])
        return false;
    
    return true;
}

void Push(int x, int y, int s)
{
    step[x][y] = s;
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

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (CanGo(nx, ny))
                Push(nx, ny, step[x][y] + 1);
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    Push(r1 - 1, c1 - 1, 0);
    BFS();

    cout << (step[r2 - 1][c2 - 1] ? step[r2 - 1][c2 - 1] : -1);

    return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n;
int board[100][100];
int half, ans;
bool visited[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y)
{
    if (!InRange(x, y))
        return false;
    if (visited[x][y])
        return false;
    
    return true;
}

void Push(int x, int y)
{
    visited[x][y] = true;
    q.push(make_pair(x, y));
}

void Reset()
{
    while (!q.empty()) q.pop();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
    }
}

bool IsPossible(int D)
{
    Reset();
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (visited[i][j])
                continue;
            
            int cnt = 1;
            Push(i, j);

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

                    if (CanGo(nx, ny) && abs(board[x][y] - board[nx][ny]) <= D)
                    {
                        Push(nx, ny);
                        cnt++;
                    }
                }
            }

            if (cnt >= half)
                return true;
        }
    }
    
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    half = (n * n + 1) / 2;

    int left = 0;
    int right = 1000000;
    
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
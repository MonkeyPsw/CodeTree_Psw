#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int puyoCnt, maxBlockSize;

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

int DFS(int x, int y)
{
    int size = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (CanGo(nx, ny) && grid[x][y] == grid[nx][ny])
        {
            visited[nx][ny] = true;
            size += DFS(nx, ny);
        }
    }

    return size;
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
        int tmp = 0;

        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                
                int sizeTmp = DFS(i, j);

                maxBlockSize = max(maxBlockSize, sizeTmp);

                if (sizeTmp >= 4)
                    puyoCnt++;
            }
        }

    }
    
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << visited[i][j];
        cout << endl;
    }
    */
    
    cout << puyoCnt << " " << maxBlockSize;

    return 0;
}
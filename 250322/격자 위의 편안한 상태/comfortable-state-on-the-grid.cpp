#include <iostream>

using namespace std;

int N, M;
int r, c;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int grid[100][100];

bool IsRange(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N);
}

int CheckPaint(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (IsRange(nx, ny) && grid[nx][ny])
            cnt++;
    }

    return cnt == 3 ? true : false;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> r >> c;

        int x = r - 1;
        int y = c - 1;

        grid[x][y]++;

        cout << CheckPaint(x, y) ? 1 : 0;
        cout << endl;
    }

    return 0;
}
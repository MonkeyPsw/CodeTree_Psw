#include <iostream>

using namespace std;

int N;
int x, y;
char grid[100][100];
bool isVisited[100][100];
int ans, dir;
// 우상좌하 +1반시계 +3시계
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int main() {
    cin >> N;
    cin >> x >> y;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int curX = --x;
    int curY = --y;
    isVisited[curX][curY] = true;

    while (true)
    {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];

        // 범위밖이면 탈출
        if (!InRange(nx, ny))
        {
            ans++;
            break;
        }

        // 루프체크
        if (isVisited[nx][ny])
        {
            ans = -1;
            break;
        }
        else
            isVisited[nx][ny] = true;

        // 이동방향이 벽이면 반시계 회전
        if (grid[nx][ny] == '#')
        {
            dir = (dir + 1) % 4;
            continue;
        }
        // 이동방향이 벽이 아니면 
        else
        {
            ans++;

            // 시계 회전해서 그 다음 이동방향 확인
            int tmpDir = (dir + 3) % 4;
            int nnx = nx + dx[tmpDir];
            int nny = ny + dy[tmpDir];

            if (grid[nnx][nny] != '#')
            {
                dir = tmpDir;
                curX = nnx;
                curY = nny;
                ans++;
                isVisited[nnx][nny] = true;
                continue;
            }
        }

        curX = nx;
        curY = ny;
    }

    cout << ans;

    return 0;
}

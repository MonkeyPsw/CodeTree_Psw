#include <iostream>
#include <algorithm>

using namespace std;

int n;
int r, c;
int a[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y)
{
    return (x > 0 && x <= n && y > 0 && y <= n);
}

int main() {
    cin >> n >> r >> c;

    // 여기 입력코드는 왜 1부터 시작이냐 아오
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int curX = r;
    int curY = c;

    while (true)
    {
        int maxNum = a[curX][curY];
        int maxX = 0, maxY = 0;
        bool canMove = false;

        cout << a[curX][curY] << " ";

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (InRange(nx, ny) && a[nx][ny] > maxNum)
            {
                maxNum = a[nx][ny];
                maxX = nx;
                maxY = ny;
                canMove = true;
                break;
            }
        }

        if (!canMove)
            break;

        curX = maxX;
        curY = maxY;
    }

    return 0;
}

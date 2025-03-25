#include <iostream>
#include <string>

using namespace std;

int N, T;
string str;
int board[100][100];

int x, y;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int d;
int cnt;

bool IsRange(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N);
}

int main() {
    cin >> N >> T;
    cin >> str;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    x = N / 2;
    y = N / 2;
    cnt += board[x][y];

    for (int i = 0; i < T; i++)
    {
        if (str[i] == 'L')
            d = (d + 3) % 4;
        else if (str[i] == 'R')
            d = (d + 1) % 4;
        else
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (IsRange(nx, ny))
            {
                x += dx[d];
                y += dy[d];
                cnt += board[x][y];
            }
        }
    }

    cout << cnt;

    return 0;
}
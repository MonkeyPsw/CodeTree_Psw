#include <iostream>

using namespace std;

int n;
char grid[1000][1000];
int k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int x, y;
int d, cnt;

bool IsRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

/*
/일떄는 0-1 2-3
\일때는 0-3 1-2
*/
void KtoXY(int d)
{
    if (d == 0) // 위에서 "아래"
    {
        x = 0;
        y = k - 1;
    }
    else if (d == 1) // 오른쪽에서 "왼쪽"
    {
        x = k - n - 1;
        y = n - 1;
    }
    else if (d == 2) // 아래에서 "위"
    {
        x = n - 1;
        y = n - (k - n - n);
    }
    else // d == 3 왼쪽에서 "오른쪽"
    {
        x = n - (k - n - n - n);
        y = 0;
    }
}

int NextDir(int x, int y, int d)
{
    int slashNextD[4] = {1, 0, 3, 2};

    if (grid[x][y] == '/')
        return slashNextD[d];
        //return d ^ 1; XOR연산이 있었구나
    else
        return 3 - d;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;
    d = (k - 1) / n;
    
    KtoXY(d);

    while (true)
    {
        d = NextDir(x, y, d);

        x += dx[d];
        y += dy[d];
        cnt++;

        if (!IsRange(x, y))
            break;
    }

    cout << cnt;

    return 0;
}
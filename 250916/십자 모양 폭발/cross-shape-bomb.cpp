#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

void Bomb(int a, int b)
{
    int size = grid[a][b] - 1;

    for (int i = a - size; i <= a + size; i++)
    {
        if (i >= 0 && i < n)
            grid[i][b] = 0;
    }

    for (int i = b - size; i <= b + size; i++)
    {
        if (i >= 0 && i < n)
            grid[a][i] = 0;
    }
}

void TmpToGrid(int b)
{
    int tmp[200] = {};
    int cnt = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (grid[i][b])
            tmp[cnt++] = grid[i][b];
    }

    for (int i = cnt; i < n; i++)
        tmp[i] = 0;

    for (int i = n - 1; i >= 0; i--)
        grid[i][b] = tmp[n - 1 - i];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    r--;
    c--;

    Bomb(r, c);

    for (int i = 0; i < n; i++)
        TmpToGrid(i);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}

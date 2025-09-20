#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int startX = n - 1;
    bool canMove = true;

    k--;

    for (int i = 0; i < n - 1; i++)
    {
        if (!canMove)
            break;

        for (int j = k; j < k + m; j++)
        {
            if (grid[i + 1][j])
            {
                startX = i;
                canMove = false;
                break;
            }
        }
    }

    for (int i = k; i < k + m; i++)
        grid[startX][i] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}

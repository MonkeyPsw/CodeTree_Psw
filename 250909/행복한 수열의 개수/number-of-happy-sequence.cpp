#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[100][100];
int ans;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = 1;

        for (int j = 0; j < n - 1; j++)
        {
            if (grid[i][j] == grid[i][j + 1])
                tmp++;
            else
                tmp = 1;

            if (tmp == m)
            {
                ans++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = 1;

        for (int j = 0; j < n - 1; j++)
        {
            if (grid[j][i] == grid[j + 1][i])
                tmp++;
            else
                tmp = 1;

            if (tmp == m)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}

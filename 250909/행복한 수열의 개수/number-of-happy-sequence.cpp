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
        int maxTmp = 1;
        int tmp = 1;

        for (int j = 0; j < n - 1; j++)
        {
            if (grid[i][j] == grid[i][j + 1])
                tmp++;
            else
            {
                maxTmp = max(maxTmp, tmp);
                tmp = 1;
            }
        }

        maxTmp = max(maxTmp, tmp);

        if (maxTmp >= m)
            ans++;
    }

    for (int i = 0; i < n; i++)
    {
        int maxTmp = 1;
        int tmp = 1;

        for (int j = 0; j < n - 1; j++)
        {
            if (grid[j][i] == grid[j + 1][i])
                tmp++;
            else
            {
                maxTmp = max(maxTmp, tmp);
                tmp = 1;
            }
        }
        
        maxTmp = max(maxTmp, tmp);

        if (maxTmp >= m)
            ans++;
    }

    cout << ans;

    return 0;
}

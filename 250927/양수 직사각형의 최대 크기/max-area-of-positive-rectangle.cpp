#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[20][20];
int ans = -1;

bool IsPositive(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (grid[i][j] <= 0)
                return false;;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] > 0)
            {
                for (int k = i; k < n; k++)
                {
                    for (int l = j; l < m; l++)
                    {
                        if (IsPositive(i, j, k, l))
                        {
                            int area = (k - i + 1) * (l - j + 1);
                            ans = max(ans, area);
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}

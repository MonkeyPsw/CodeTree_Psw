#include <iostream>

using namespace std;

int N;
char grid[10][10];
int ans;

void Flip(int x, int y)
{
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
            grid[i][j] ^= 1;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (grid[i][j] == '1')
            {
                Flip(i, j);
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}

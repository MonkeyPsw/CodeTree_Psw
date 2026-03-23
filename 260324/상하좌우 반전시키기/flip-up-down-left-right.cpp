#include <iostream>

using namespace std;

int n;
int arr[100][100];
int ans;
int dx[3] = {0, 1, 0}, dy[3] = {-1, 0, 1};

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

/*
void Print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}
*/

void Push(int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (InRange(nx, ny))
            arr[nx][ny] ^= 1;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i - 1][j] == 0)
            {
                arr[i - 1][j] ^= 1;
                arr[i][j] ^= 1;

                Push(i, j);

                //Print();

                ans++;
            }
        }
    }

    if (arr[n - 1][n - 1] == 0)
        cout << -1;
    else
        cout << ans;

    return 0;
}

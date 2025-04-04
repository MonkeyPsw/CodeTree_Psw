#include <iostream>
#include <string>

using namespace std;

int N, M;
string arr[50];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ans;

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 'L')
            {
                for (int k = 0; k < 8; k++)
                {
                    int cnt = 0;
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (!InRange(nx, ny))
                        continue;
                    
                    while (InRange(nx, ny) && arr[nx][ny] == 'E')
                    {
                        cnt++;
                        
                        if (cnt >= 2)
                        {
                            ans++;
                            break;
                        }

                        nx += dx[k];
                        ny += dy[k];
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
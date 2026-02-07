#include <iostream>

using namespace std;

int n, m, k;
int preSum[3][1001][1001];

int GetNum(char c)
{
    if (c == 'a')
        return 0;
    else if (c == 'b')
        return 1;
    
    return 2;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;

            int num = GetNum(x);

            for (int cnt = 0; cnt < 3; cnt++)
            {
                preSum[cnt][i][j] = preSum[cnt][i - 1][j] +
                                  preSum[cnt][i][j - 1] -
                                  preSum[cnt][i - 1][j - 1];
            }
            
            preSum[num][i][j]++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        for (int j = 0; j < 3; j++)
            cout << preSum[j][r2][c2] - preSum[j][r1 - 1][c2] - preSum[j][r2][c1 - 1] + preSum[j][r1 - 1][c1 - 1] << " ";
        cout << endl;
    }

    return 0;
}

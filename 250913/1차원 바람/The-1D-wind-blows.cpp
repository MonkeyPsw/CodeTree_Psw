#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

// 왼쪽에서 부는 바람, 오른쪽 쉬프트
void LeftWind(int i)
{
    int tmp = a[i][m - 1];

    for (int j = m - 1; j >= 1; j--)
        a[i][j] = a[i][j - 1];

    a[i][0] = tmp;
}

// 오른쪽에서 부는 바람, 왼쪽 쉬프트
void RightWind(int i)
{
    int tmp = a[i][0];

    for (int j = 0; j < m - 1; j++)
        a[i][j] = a[i][j + 1];
    
    a[i][m - 1] = tmp;
}

bool CheckNum(int curRow, int nextRow)
{
    for (int i = 0; i < m; i++)
    {
        if (a[curRow][i] == a[nextRow][i])
            return true;
    }

    return false;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        bool isRight = false;
        r--;

        if (d = 'L')
        {
            LeftWind(r);
            isRight = true;
        }
        else
            RightWind(r);
        
        for (int j = r; j >= 1; j--)
        {
            if (CheckNum(j, j - 1))
            {
                if (isRight)
                {
                    RightWind(j - 1);
                    isRight = false;
                }
                else
                {
                    LeftWind(j - 1);
                    isRight = true;
                }
            }
        }

        if (d = 'L')
            isRight = true;

        for (int j = r; j < n - 1; j++)
        {
            if (CheckNum(j, j + 1))
            {
                if (isRight)
                    RightWind(j + 1);
                else
                    LeftWind(j + 1);
                
                isRight = !isRight;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int n;
int bNum[10], str[10], ball[10];
int ans;

int StrikeCheck(int a, int b)
{
    int strCnt = 0;

    while (b)
    {
        if (a % 10 == b % 10)
            strCnt++;
        
        a /= 10;
        b /= 10;
    }

    return strCnt;
}

int BallCheck(int a, int b)
{
    int ballCnt = 0;
    int a1 = a / 100;
    int a2 = a % 100 / 10;
    int a3 = a % 10;

    if (a1 == b % 10 || a2 == b % 10)
        ballCnt++;

    b /= 10;

    if (a1 == b % 10 || a3 == b % 10)
        ballCnt++;
        
    b /= 10;

    if (a2 == b % 10 || a3 == b % 10)
        ballCnt++;

    /*
    int b1 = b / 100, b2 = b % 100 / 10, b3 = b % 10;

    if (a1 == b2 || a1 == b3)
        ballCnt++;
    if (a2 == b1 || a2 == b3)
        ballCnt++;
    if (a3 == b1 || a3 == b2)
        ballCnt++;
    */
    
    return ballCnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> bNum[i] >> str[i] >> ball[i];

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (j == i)
                continue;
            for (int k = 1; k < 10; k++)
            {
                if (k == i || k == j)
                    continue;
                
                int aNum = i * 100 + j * 10 + k;
                bool isRight = true;

                for (int l = 0; l < n; l++)
                {
                    if (!StrikeCheck(aNum, bNum[l]) == str[l] ||
                        !BallCheck(aNum, bNum[l]) == ball[l])
                        {
                            isRight = false;
                            break;
                        }
                }

                if (isRight)
                    ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
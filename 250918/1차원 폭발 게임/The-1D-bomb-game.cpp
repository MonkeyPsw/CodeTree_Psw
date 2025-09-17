#include <iostream>

using namespace std;

int n, m;
int numbers[100];
int beforeCnt, afterCnt;

int TmpToNumbers(int cnt)
{
    int tmp[100] = {};
    int tmpCnt = 0;

    for (int i = 0; i < cnt; i++)
    {
        if (numbers[i])
            tmp[tmpCnt++] = numbers[i];
    }

    for (int i = 0; i < tmpCnt; i++)
        numbers[i] = tmp[i];
    
    return tmpCnt;
}

void FillNumbersZero(int start, int end)
{
    for (int i = start; i < end; i++)
        numbers[i] = 0;
}

void CheckNumCnt(int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        if (!numbers[i])
            continue;

        int numCnt = 1;

        for (int j = i + 1; j < cnt; j++)
        {
            if (numbers[i] == numbers[j])
                numCnt++;
            else
                break;
        }
        
        if (numCnt >= m)
            FillNumbersZero(i, i + numCnt);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    CheckNumCnt(n);
    beforeCnt = TmpToNumbers(n);

    while (true)
    {
        CheckNumCnt(beforeCnt);
        afterCnt = TmpToNumbers(beforeCnt);

        if (afterCnt == beforeCnt)
            break;

        beforeCnt = afterCnt;
    }

    cout << afterCnt << endl;

    for (int i = 0; i < afterCnt; i++)
        cout << numbers[i] << endl;

    return 0;
}
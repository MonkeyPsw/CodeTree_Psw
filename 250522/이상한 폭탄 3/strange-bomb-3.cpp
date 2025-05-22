#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int num[100];
bool isBomb[100];
int idx[1000001];

int checkBomb()
{
    int maxBomb = 0;
    int maxCnt = 0;

    for (int i = 0; i <= 1000000; i++)
    {
        if (idx[i] > 0)
        {
            maxCnt = max(maxCnt, idx[i]);

            if (idx[i] == maxCnt)
                maxBomb = i;
        }
    }

    return maxBomb;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (isBomb[i] && isBomb[j])
                continue;
            
            if (num[i] == num[j] && (j - i) <= K)
            {
                if (!isBomb[i])
                    idx[num[i]]++;
                
                if (!isBomb[j])
                    idx[num[j]]++;

                isBomb[i] = true;
                isBomb[j] = true;
            }
        }
    }

    cout << checkBomb();

    return 0;
}
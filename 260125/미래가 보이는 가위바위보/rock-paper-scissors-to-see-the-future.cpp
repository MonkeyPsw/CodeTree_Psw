#include <iostream>
#include <algorithm>

using namespace std;

int N;
char B[100000];
int rL[100000], rR[100000];
int sL[100000], sR[100000];
int pL[100000], pR[100000]; // 생각해보니 처음과 끝 초기화 안해도 되겠네
int rWinCnt, sWinCnt, pWinCnt;
int rToS, rToP, sToR, sToP, pToR, pToS;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (B[i] == 'H')
            pWinCnt++;
        else if (B[i] == 'S')
            rWinCnt++;
        else
            sWinCnt++;

        rL[i] = rWinCnt;
        pL[i] = pWinCnt;
        sL[i] = sWinCnt;
    }

    rWinCnt = sWinCnt = pWinCnt = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (B[i] == 'H')
            pWinCnt++;
        else if (B[i] == 'S')
            rWinCnt++;
        else
            sWinCnt++;

        rR[i] = rWinCnt;
        pR[i] = pWinCnt;
        sR[i] = sWinCnt;
    }

    int onlyOneMax = max({rL[N - 1], sL[N - 1], pL[N - 1]});

    for (int k = 1; k < N - 1; k++)
    {
        rToS = max(rToS, rL[k] + sR[k + 1]);
        rToP = max(rToP, rL[k] + pR[k + 1]);
        sToR = max(sToR, sL[k] + rR[k + 1]);
        sToP = max(sToP, sL[k] + pR[k + 1]);
        pToR = max(pToR, pL[k] + rR[k + 1]);
        pToS = max(pToS, pL[k] + sR[k + 1]);
    }

    int dualMax = max({rToS, rToP, sToR, sToP, pToR, pToS});

    cout << max(onlyOneMax, dualMax);

    return 0;
}

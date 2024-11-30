#include <iostream>
using namespace std;

int main() {
    int num;
    int up[10], down[10];
    int upCnt = 0, downCnt = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        if (num > 500)
            up[upCnt++] = num;
        else
            down[downCnt++] = num;
    }

    int downMax = down[0];
    int upMin = up[0];
    
    for (int i = 1; i < downCnt; i++)
    {
        if (down[i] > downMax)
            downMax = down[i];
    }
    for (int i = 1; i < upCnt; i++)
    {
        if (up[i] < upMin)
            upMin = up[i];
    }

    cout << downMax << " " << upMin;
    
    return 0;
}
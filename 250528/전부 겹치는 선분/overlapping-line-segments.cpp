#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1[100], x2[100];
int x1Max, x2Min = 101;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        x1Max = max(x1Max, x1[i]);
        x2Min = min(x2Min, x2[i]);
    }

    if (x1Max <= x2Min)
        cout << "Yes";
    else
        cout << "No";

    // x1시작점 중 가장 큰 값과 x2끝점 중 가장 작은 값을 비교

    /* 의도에 맞는 풀이가 아니긴 했다
    for (int i = 1; i <= 100; i++)
    {
        bool isOverlap = true;

        for (int j = 0; j < n; j++)
        {
            if (i < x1[j] || i > x2[j])
            {
                isOverlap = false;
                break;
            }
        }

        if (isOverlap)
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    */

    return 0;
}
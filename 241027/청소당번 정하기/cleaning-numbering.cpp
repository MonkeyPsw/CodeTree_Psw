#include <iostream>
using namespace std;

int main() {
    int n, cnt2 = 0, cnt3 = 0, cnt12 = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            if (i % 12 == 0)
                cnt12++;
            else if (i % 3 == 0)
                cnt3++;
            else
                cnt2++;
        }
        else if (i % 3 == 0)
        {
            if (i % 12 == 0)
                cnt12++;
            else if (i % 2 == 0)
                cnt2++;
            else
                cnt3++;
        }
        else if (i % 12 == 0)
            cnt12++;
    }

    /* 처음에 이렇게 한거같았는데 왜 안됐지?
    for(int i = 1; i <= n; i++) {
        // 주기가 가장 긴 12일부터 확인합니다.
        if(i % 12 == 0)
            cnt12++;
        // 12일 주기에 들어오지 않는다면, 3일 주기에 들어오는지 확인합니다.
        else if(i % 3 == 0)
            cnt3++;
        // 3일 주기에도 들어오지 않는다면, 2일 주기에 들어오는지 확인합니다.
        else if(i % 2 == 0)
            cnt2++;
    }
    */

    cout << cnt2 << " " << cnt3 << " " << cnt12;
    return 0;
}
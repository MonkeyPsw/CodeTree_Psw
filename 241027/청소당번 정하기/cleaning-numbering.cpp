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
    cout << cnt2 << " " << cnt3 << " " << cnt12;
    return 0;
}
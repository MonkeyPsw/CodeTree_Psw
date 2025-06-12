#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[101];
int ans = -1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int firstMin = 101;
    for (int i = 1; i <= n; i++)
        firstMin = min(firstMin, a[i]);
    
    /*
    int secondMin = 101;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != firstMin)
        {
            if (a[i] != secondMin)
            {
                int tmp = secondMin;
                secondMin = min(secondMin, a[i]);
                
                if (tmp != secondMin)
                    ans = i;
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
    }
    */

    int secondMin = 101;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != firstMin)
        {
            int tmp = secondMin;
            secondMin = min(secondMin, a[i]);

            if (tmp != secondMin)
                ans = i;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == secondMin)
            cnt++;
    }

    if (cnt == 1)
        cout << ans;
    else
        cout << -1;

    return 0;
}
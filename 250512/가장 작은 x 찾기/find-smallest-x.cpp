#include <iostream>

using namespace std;

int n;
int a[10], b[10];
int ans = 1;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    while (true)
    {
        int tmp = ans;
        bool inRange = true;

        tmp *= 2;

        for (int i = 0; i < n; i++)
        {
            if (tmp >= a[i] && tmp <= b[i])
                tmp *= 2;
            else
            {
                inRange = false;
                break;
            }
        }

        if (inRange)
            break;
        else
            ans++;
    }

    cout << ans;

    return 0;
}
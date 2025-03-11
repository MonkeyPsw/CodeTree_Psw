#include <iostream>

using namespace std;

int n, m, length;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];
int a[1000001];
int b[1000001];
int cur;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> t[i];

        for (int j = cur; j < t[i]; j++)
        {
            if (d[i] == 'R')
                a[j] = a[j - 1] + 1;
            else
                a[j] = a[j - 1] - 1;
        }

        cur += t[i];
    }

    cur = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> d2[i] >> t2[i];

        for (int j = cur; j < t2[i]; j++)
        {
            if (d2[i] == 'R')
                b[j] = b[j - 1] + 1;
            else
                b[j] = b[j - 1] - 1;
        }

        cur += t2[i];
    }

    int ans = -1;

    for (int i = 1; i < 1000001; i++)
    {
        if (a[i] == b[i])
        {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}
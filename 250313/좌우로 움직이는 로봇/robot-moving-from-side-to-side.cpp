#include <iostream>

using namespace std;

int n, m;
int t_a[50000];
char d_a[50000];
int t_b[50000];
char d_b[50000];
int a[1000001], b[1000001];
int cur_a = 1, cur_b = 1;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t_a[i] >> d_a[i];

        for (int j = cur_a; j <= cur_a + t_a[i]; j++)
        {
            if (d_a[i] == 'R')
                a[j] = a[j - 1] + 1;
            else
                a[j] = a[j - 1] - 1;
        }

        cur_a += t_a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> t_b[i] >> d_b[i];

        for (int j = cur_b; j <= cur_b + t_b[i]; j++)
        {
            if (d_b[i] == 'R')
                b[j] = b[j - 1] + 1;
            else
                b[j] = b[j - 1] - 1;
        }

        cur_b += t_b[i];
    }

    int cnt = 0;

    if (cur_a > cur_b)
    {
        for (int i = 2; i < cur_a; i++)
        {
            if (i >= cur_b)
            {
                if (a[i] == b[cur_b - 1])
                {
                    if (a[i - 1] != b[cur_b - 1])
                        cnt++;
                }
            }
            else
            {
                if (a[i] == b[i])
                {
                    if (a[i - 1] != b[i - 1])
                        cnt++;
                }
            }
        }
    }
    else
    {
        for (int i = 2; i < cur_b; i++)
        {
            if (i >= cur_a)
            {
                if (a[cur_a - 1] == b[i])
                {
                    if (a[cur_a - 1] != b[i - 1])
                        cnt++;
                }
            }
            else
            {
                if (a[i] == b[i])
                {
                    if (a[i - 1] != b[i - 1])
                        cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
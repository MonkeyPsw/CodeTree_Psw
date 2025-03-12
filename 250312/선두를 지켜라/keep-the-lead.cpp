#include <iostream>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];
int a[1000001], b[1000001];
int cur = 1;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i] >> t[i];

        for (int j = cur; j <= cur + t[i]; j++)
            a[j] = a[j - 1] + v[i];

        cur += t[i];
    }

    cur = 1;

    for (int i = 0; i < M; i++)
    {
        cin >> v2[i] >> t2[i];

        for (int j = cur; j <= cur + t2[i]; j++)
            b[j] = b[j - 1] + v2[i];

        cur += t2[i];
    }
    
    int cnt = 0;
    bool isSame = false;

    for (int i = 1; i < cur; i++)
    {
        if (isSame && a[i - 1] == b[i - 1])
        {
            if (a[i] != b[i])
            {
                isSame = false;
                cnt++;
            }
        }

        if (!isSame && a[i] == b[i])
        {
            isSame = true;
            continue;
        }
    }

    cout << cnt;

    return 0;
}
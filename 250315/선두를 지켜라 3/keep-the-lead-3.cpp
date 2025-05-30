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
    int lead = 0;
    // 0 : 같음, 1 : a가 선두, 2 : b가 선두

    for (int i = 1; i < cur; i++)
    {
        if (a[i] > b[i])
        {
            if (lead == 2 || lead == 0)
                cnt++;
            
            lead = 1;
        }
        else if (a[i] < b[i])
        {
            if (lead == 1 || lead == 0)
                cnt++;
            
            lead = 2;
        }
        else
        {
            if (lead == 1 || lead == 2)
                cnt++;
            
            lead = 0;
        }
    }

    cout << cnt;

    return 0;
}
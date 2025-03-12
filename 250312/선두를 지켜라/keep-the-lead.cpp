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
    //int pre = 0; // a[0] == b[0]
    // 0 : 같음, 1 : a가 선두, 2 : b가 선두
    int lead = 0;

    for (int i = 1; i < cur; i++)
    {
        /*
        int lead = -1;

        if (a[i] > b[i])
            lead = 1;
        else if (a[i] < b[i])
            lead = 2;
        else
            lead = pre;

        // a[0] == b[0] 이후에 처음 선두가 바뀌는건 제외
        if (pre != 0 && lead != pre)
            cnt++;

        pre = lead;
        */

        if (a[i] > b[i])
        {
            if (lead == 2)
                cnt++;
            
            lead = 1;
        }
        else if (a[i] < b[i])
        {
            if (lead == 1)
                cnt++;
            
            lead = 2;
        }
    }

    cout << cnt;

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1[100], x2[100];
//int ans = 100;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    /* 완전탐색
    for (int i = 0; i < n; i++)
    {
        int start = 100, end = 0;

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                start = min(start, x1[j]);
                end = max(end, x2[j]);
            }
        }

        int cnt = end - start;
        ans = min(ans, cnt);
    }

    cout << ans;
    */

    // 선분이 짧아지려면 맨 왼쪽의 가장 작은 점이 포함된 선분이나
    // 맨 오른쪽의 가장 큰 점이 포함된 선분을 지워야 함
    // 그 두개의 점을 각각 지워보고 길이를 비교해서 최소 선분 길이 확인

    int left = 0, right = 0;
    for (int i = 1; i < n; i++)
    {
        if (x1[left] > x1[i])
            left = i;
        if (x2[right] < x2[i])
            right = i;
    }

    int smallStart = 100, smallEnd = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != left)
        {
            smallStart = min(smallStart, x1[i]);
            smallEnd = max(smallEnd, x2[i]);
        }
    }
    int cnt1 = smallEnd - smallStart;

    int bigStart = 100, bigEnd = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != right)
        {
            bigStart = min(bigStart, x1[i]);
            bigEnd = max(bigEnd, x2[i]);
        }
    }
    int cnt2 = bigEnd - bigStart;

    cout << min(cnt1, cnt2);

    return 0;
}
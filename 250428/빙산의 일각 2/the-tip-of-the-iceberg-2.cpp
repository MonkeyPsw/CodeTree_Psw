#include <iostream>
#include <algorithm>

using namespace std;

int n;
int h[100];
int maxH;
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];

        maxH = max(maxH, h[i]);
    }

    /* GPT와 claude의 추천
    for (int i = 1; i <= maxH; i++)
    {
        int cnt = 0;
        bool isAbove = false;

        for (int j = 0; j < n; j++)
        {
            if (h[j] > i)
            {
                if (!isAbove)
                {
                    cnt++;
                    isAbove = true;
                }
            }
            else
                isAbove = false;
        }

        ans = max(ans, cnt);
    }
    */

    /* 이거 대체 반례가 뭐지 내가 뭘 잘못했지 새벽감성 실패
    for (int i = 1; i <= maxH; i++)
    {
        int cnt = 0;

        for (int j = 0; j < n - 1; j++)
        {
            if (h[j] - i > 0 && h[j + 1] - i <= 0)
                cnt++;
        }

        if (h[n - 1] - i > 0 && h[n - 2] - i <= 0)
            cnt++;

        ans = max(ans, cnt);
    }
    */

    // 아니 설마 1부터 시작하는건가 했는데 진짜네
    for (int i = 1; i <= maxH; i++)
    {
        int cnt = 0;

        if (h[0] > i)
            cnt++;

        for (int j = 1; j < n ; j++)
        {
            if (h[j] - i > 0 && h[j - 1] - i <= 0)
                cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
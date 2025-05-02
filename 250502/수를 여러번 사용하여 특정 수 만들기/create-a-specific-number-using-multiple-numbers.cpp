#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;
int ans;

int main() {
    cin >> A >> B >> C;

    for (int i = 0; i < C / A + 1; i++)
    {
        for (int j = 0; j < C / B + 1; j++)
        {
            if (A * i + B * j <= C)
                ans = max(ans, A * i + B * j);
        }
    }

    /* for문 한번으로 되는구나 시간을 생각하면
    // a를 몇 회 사용할지 전부 시도해 봅니다.
    // 모든 경우의 수에 대해 최대가 되도록 하는 수를 계산합니다.
    for(int i = 0; i * a <= c; i++) {
        // a를 i회 사용합니다.
        int cnt = a * i;

        // 값을 최대로 하기 위해 b를 몇회 사용해야 하는지 계산합니다.
        int num_b = (c - cnt) / b;

        cnt += num_b * b;
        
        ans = max(ans, cnt);
    }
    */

    cout << ans;

    return 0;
}
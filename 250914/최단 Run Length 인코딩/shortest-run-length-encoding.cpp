#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string A;
int ans = INT_MAX;

void RightShift()
{
    char tmp = A[A.length() - 1];

    for (int i = A.length() - 1; i >= 1; i--)
        A[i] = A[i - 1];
    
    A[0] = tmp;
}

int RunLength(string s)
{
    int cnt = 1;
    int sameCnt = 0;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cnt++;
            sameCnt = 0;
        }

        sameCnt++;
    }

    // 마음에 안드는데 으앙
    if (sameCnt >= 9)
        return cnt * 2 + 1;
    
    return cnt * 2;
}

int main() {
    cin >> A;

    for (int i = 0; i < A.length(); i++)
    {
        ans = min(ans, RunLength(A));

        RightShift();
    }

    cout << ans;

    return 0;
}

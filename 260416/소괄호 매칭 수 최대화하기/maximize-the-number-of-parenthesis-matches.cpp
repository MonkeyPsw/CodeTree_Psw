#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
string s[100000];
tuple<int, int, long long> t[100000];
long long ans;

bool cmp(const tuple<int, int, long long>& a, const tuple<int, int, long long>& b)
{
    int left1, right1;
    tie(left1, right1, ignore) = a;

    int left2, right2;
    tie(left2, right2, ignore) = b;

    return (long long)left1 * right2 > left2 * right1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }


    for (int i = 0; i < n; i++)
    {
        long long score = 0;
        int openCnt = 0;
        int leftCnt = 0;
        int rightCnt = 0;

        for (int j = 0; j < s[i].length(); j++)
        {
            if (s[i][j] == '(')
            {
                openCnt++;
                leftCnt++;
            }
            else
            {
                score += openCnt;
                rightCnt++;
            }
        }

        t[i] = make_tuple(leftCnt, rightCnt, score);
    }

    sort(t, t + n, cmp);

    int open = 0;
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = 0;
        long long tmp = 0;
        tie(left, right, tmp) = t[i];

        ans += tmp;
        ans += open * right;
        open += left;
    }

    cout << ans;

    return 0;
}

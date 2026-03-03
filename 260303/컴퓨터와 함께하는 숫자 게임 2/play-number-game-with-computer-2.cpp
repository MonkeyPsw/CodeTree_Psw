#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long m;
long long a, b;
long long minAns = LLONG_MAX, maxAns = LLONG_MIN;

long long SearchNum(long long num)
{
    int cnt = 0;
    long long left = 1, right = m;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        cnt++;

        if (mid == num)
            break;

        if (mid > num)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return cnt;
}

int main() {
    cin >> m;
    cin >> a >> b;

    for (long long i = a; i <= b; i++)
    {
        minAns = min(minAns, SearchNum(i));
        maxAns = max(maxAns, SearchNum(i));
    }

    cout << minAns << " " << maxAns;

    return 0;
}

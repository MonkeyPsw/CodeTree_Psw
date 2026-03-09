#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;
long long ans;

bool IsPossible(long long num)
{
    long long cnt = 0;

    for (long long i = 1; i <= n; i++)
        cnt += min(n, num / i);
    
    if (cnt >= k)
        return true;
    
    return false;
}

int main() {
    cin >> n;
    cin >> k;

    long long left = 1;
    long long right = k;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}

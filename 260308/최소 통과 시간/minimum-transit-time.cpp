#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[100000];
int maxTime;
long long ans = LLONG_MAX;

bool IsPossible(long long time)
{
    long long sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum += time / arr[i];

        if (sum >= n)
            return true;
    }
    
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];

        maxTime = max(maxTime, arr[i]);
    }

    long long left = 1;
    long long right = (long long)n * maxTime;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}

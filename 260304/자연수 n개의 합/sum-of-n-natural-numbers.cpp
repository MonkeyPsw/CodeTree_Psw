#include <iostream>
#include <algorithm>

using namespace std;

long long s;
long long ans;

int main() {
    cin >> s;

    long long left = 1;
    long long right = s;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (mid <= (2 * s) / (mid + 1))
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}

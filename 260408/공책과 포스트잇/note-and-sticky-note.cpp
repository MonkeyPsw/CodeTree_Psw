#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int N, K, L;
int c[100000];
int ans;

bool IsPossible(int num)
{
    long long sum = 0;

    for (int i = 0; i < num; i++)
    {
        int cnt = max(0, num - c[i]);

        if (cnt > K)
            return false;

        sum += cnt;
    }

    if (sum <= (long long)K * L)
        return true;
    
    return false;
}

int main() {
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    sort(c, c + N, greater<int>());

    int left = 1;
    int right = N;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}

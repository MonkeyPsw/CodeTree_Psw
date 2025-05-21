#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[100];
int ans = INT_MAX;

bool IsPossible(int num)
{
    int idx[100] = {};
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= num)
            idx[cnt++] = i;
    }

    for (int i = 1; i < cnt; i++)
    {
        int dist = idx[i] - idx[i - 1];

        if (dist > k)
            return false;
    }

    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = max(arr[0], arr[n - 1]); i <= 100; i++)
    {
        if (IsPossible(i))
            ans = min(ans, i);
    }

    cout << ans;

    return 0;
}
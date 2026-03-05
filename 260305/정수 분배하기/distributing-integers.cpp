#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10000];
int sum, ans;

bool IsPossible(int k)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt += arr[i] / k;

        if (cnt >= m)
            return true;
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    int left = 1;
    int right = sum / m;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
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

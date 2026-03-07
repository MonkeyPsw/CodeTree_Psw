#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[200000];
int ans;

bool IsPossible(int num)
{
    int cnt = 1;
    int prev = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - prev >= num)
        {
            cnt++;
            prev = arr[i];
        }
    }

    if (cnt >= m)
        return true;
    
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 1;
    int right = arr[n - 1] - arr[0];

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

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int x[50000];
int ans;

bool IsPossible(int r)
{
    int bomb = 0;
    int i = 0;
    
    while (i < n)
    {
        int range = x[i] + 2 * r;
        bomb++;

        while (i < n && x[i] <= range)
            i++;
    }

    if (bomb <= k)
        return true;
    
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int left = 1;
    int right = 500000000;

    while (left <= right)
    {
        int mid = (left + right) / 2;

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

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int x1[100000], x2[100000];
pair<int, int> p[100000];
int ans;

bool IsPossible(int dist)
{
    int last = p[0].first;

    for (int i = 1; i < n; i++)
    {
        last = max(p[i].first, last + dist);

        if (last > p[i].second)
            return false;
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n; i++)
        p[i] = make_pair(x1[i], x2[i]);

    sort(p, p + n);

    int left = 1;
    int right = 1000000000;

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
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
long long a[100000], b[100000];
pair<long long, long long> p[100000];
long long ans;

bool IsPossible(long long dist)
{
    int cnt = 1;
    long long last = p[0].first;

    for (int i = 0; i < M; i++)
    {
        long long pos = max(p[i].first, last + dist);

        while (pos <= p[i].second)
        {
            cnt++;
            last = pos;
            pos += dist;
        }

        if (cnt >= N)
            return true;
    }

    return false;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < M; i++)
        p[i] = make_pair(a[i], b[i]);
    
    sort(p, p + M);

    long long left = 1;
    long long right = 1e18;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

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

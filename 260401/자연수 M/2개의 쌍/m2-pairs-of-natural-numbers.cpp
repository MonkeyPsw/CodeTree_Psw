#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int x[100000], y[100000];
pair<int, int> p[100000];
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; i++)
        p[i] = make_pair(y[i], x[i]);
    
    sort(p, p + N);

    int left = 0;
    int right = N - 1;

    while (left <= right)
    {
        if (left == right)
        {
            if (p[left].second >= 2)
                ans = max(ans, p[left].first * 2);

            break;
        }

        int cnt = min(p[left].second, p[right].second);

        ans = max(ans, p[left].first + p[right].first);

        p[left].second -= cnt;
        p[right].second -= cnt;

        if (p[left].second == 0)
            left++;
        if (p[right].second == 0)
            right--;
    }

    cout << ans;

    return 0;
}

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int x1[100000], x2[100000];
pair<int, int> line[200000];
int cnt, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n; i++)
    {
        line[i] = make_pair(x1[i], 1);
        line[i + n] = make_pair(x2[i], -1);
    }

    sort(line, line + 2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
        cnt += line[i].second;

        if (ans < cnt)
            ans = cnt;
    }

    cout << ans;

    return 0;
}

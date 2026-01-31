#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int n;
int a[MAX_N], b[MAX_N];
pair<int, int> line[200000];
int sum, ans, startIdx;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        line[i] = make_pair(a[i], 1);
        line[i + n] = make_pair(b[i], -1);
    }
    
    sort(line, line + 2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
        if (line[i].second == 1 && sum == 0)
            startIdx = line[i].first;

        sum += line[i].second;

        if (line[i].second == -1 && sum == 0)
            ans = max(ans, line[i].first - startIdx);
    }

    cout << ans;

    return 0;
}

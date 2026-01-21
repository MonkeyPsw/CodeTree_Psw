#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int a[100000], b[100000];
pair<int, int> line[200000];
int sum, ans;

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
            ans++;

        sum += line[i].second;
    }

    cout << ans;

    return 0;
}
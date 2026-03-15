#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int s[100000];
int e[100000];
pair<int, int> p[100000];
int cur, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }

    for (int i = 0; i < n; i++)
        p[i] = make_pair(e[i], s[i]);
    
    sort(p, p + n);

    for (int i = 0; i < n; i++)
    {
        if (p[i].second >= cur)
        {
            ans++;
            cur = p[i].first;
        }
    }

    cout << ans;

    return 0;
}

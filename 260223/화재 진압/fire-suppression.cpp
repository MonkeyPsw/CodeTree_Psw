#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m;
int fires[100000];
int stations[100000];
int j, ans;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> fires[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> stations[i];
    }

    sort(fires, fires + n);
    sort(stations, stations + m);

    for (int i = 0; i < n; i++)
    {
        while (j + 1 < m && abs(stations[j + 1] - fires[i]) <= abs(stations[j] - fires[i]))
            j++;

        ans = max(ans, abs(stations[j] - fires[i]));
    }

    cout << ans;

    return 0;
}

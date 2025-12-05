#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int x[100000], y[100000];
unordered_map<int, int> uMap;
long long ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        if (!uMap[x[i]])
            uMap[x[i]] = y[i];
        else
        {
            if (uMap[x[i]] > y[i])
            {
                ans -= uMap[x[i]];
                uMap[x[i]] = y[i];
            }
            else
                continue;
        }

        ans += uMap[x[i]];
    }

    cout << ans;

    return 0;
}
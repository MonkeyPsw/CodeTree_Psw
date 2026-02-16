#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

int n;
int a[100000];
int ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        ans = min(ans, abs(a[i] + a[j]));

        if (a[i] + a[j] > 0)
            j--;
        else
            i++;
    }

    cout << ans;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int a[100000];
int num, sum;
int ans = INT_MIN;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (num < n)
    {
        sum += a[num];

        sum = max(sum, a[num]);

        ans = max(ans, sum);
        
        num++;
    }

    cout << ans;

    return 0;
}

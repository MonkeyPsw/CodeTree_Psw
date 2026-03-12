#include <iostream>

using namespace std;

int n, k;
int coins[10];
int ans, sum;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (sum + coins[i] <= k)
        {
            ans++;
            sum += coins[i];
        }
    }

    cout << ans;

    return 0;
}

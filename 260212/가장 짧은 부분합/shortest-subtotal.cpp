#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, s;
int arr[100000];
int sum, j;
int ans = INT_MAX;

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (j < n && sum < s)
        {
            sum += arr[j];
            j++;
        }

        if (sum >= s)
            ans = min(ans, j - i);

        sum -= arr[i];
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}

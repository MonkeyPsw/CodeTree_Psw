#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100];
int ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = i;
        int sum = 0;

        for (int j = 0; j < m; j++)
        {
            sum += arr[cnt];

            cnt = arr[cnt];
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
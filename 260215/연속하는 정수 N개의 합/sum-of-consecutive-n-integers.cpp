#include <iostream>

using namespace std;

int n, m;
int arr[100000];
int sum, j;
int ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (j < n && sum < m)
        {
            sum += arr[j];
            j++;
        }

        if (sum == m)
            ans++;

        sum -= arr[i];
    }

    cout << ans;

    return 0;
}
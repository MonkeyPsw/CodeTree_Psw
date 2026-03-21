#include <iostream>

using namespace std;

int n;
int arr[100];
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == 0)
        {
            if (i == n - 1)
            {
                arr[i - 1] ^= 1;
                arr[i] ^= 1;
            }

            else
            {
                arr[i - 1] ^= 1;
                arr[i] ^= 1;
                arr[i + 1] ^= 1;
            }

            ans++;
        }
    }

    if (arr[n - 1] == 0)
        cout << -1;
    else
        cout << ans;

    return 0;
}

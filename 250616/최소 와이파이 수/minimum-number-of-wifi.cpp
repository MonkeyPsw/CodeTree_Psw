#include <iostream>

using namespace std;

int n, m;
int arr[100];
int ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            i += m + 1;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
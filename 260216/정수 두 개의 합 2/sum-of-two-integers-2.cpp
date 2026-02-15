#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[100000];
long long ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] <= k)
        {
            ans += j - i;
            i++;
        }
        else
            j--;
    }

    cout << ans;

    return 0;
}

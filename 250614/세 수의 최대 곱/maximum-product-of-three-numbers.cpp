#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    /*
    int tmp1 = max(arr[0] * arr[1] * arr[2], arr[0] * arr[1] * arr[n - 1]);
    int tmp2 = max(arr[0] * arr[n - 2] * arr[n - 1], arr[n - 3] * arr[n - 2] * arr[n - 1]);

    cout << max(tmp1, tmp2);
    */

    // 이거만 있어도 되겠구나
    cout << max(arr[0] * arr[1] * arr[n - 1], arr[n - 3] * arr[n - 2] * arr[n - 1]);

    return 0;
}
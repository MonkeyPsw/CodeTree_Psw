#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
int arr[100000];
int a[100000], b[100000];
int leftArr[100000], rightArr[100000];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < q; i++) cin >> a[i] >> b[i];

    leftArr[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftArr[i] = max(leftArr[i - 1], arr[i]);
    
    rightArr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightArr[i] = max(rightArr[i + 1], arr[i]);

    for (int i = 0; i < q; i++)
        cout << max(leftArr[a[i] - 2], rightArr[b[i]]) << endl;

    return 0;
}

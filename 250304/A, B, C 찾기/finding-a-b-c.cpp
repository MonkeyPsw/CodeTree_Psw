#include <iostream>
#include <algorithm>

using namespace std;

int arr[7];

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 7);

    int a = arr[6] - arr[5];
    int c = arr[4] - a;
    int b = arr[6] - a - c;

    cout << a << " " << b << " " << c;

    return 0;
}
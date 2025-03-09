#include <iostream>

using namespace std;

int n, t;
int arr[1000];

int main() {
    int max = 0, cnt = 0;

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (i == 0)
            continue;

        if (arr[i] > t)
            cnt++;
        else
        {
            if (max < cnt)
                max = cnt;
            cnt = 0;
        }
    }

    if (max < cnt)
        max = cnt;

    cout << max;

    return 0;
}
#include <iostream>

using namespace std;

int N;
int arr[1000];

int main() {
    int max = 1, cnt = 1;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (i == 0)
            continue;

        if (arr[i] > arr[i - 1])
            cnt++;
        else
        {
            if (max < cnt)
                max = cnt;
            cnt = 1;
        }
    }

    if (max < cnt)
        max = cnt;

    cout << max;

    return 0;
}
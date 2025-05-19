#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[1000];
int ans = -1;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    /*
    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        int min = arr[i];
        int cnt = 0;

        if (i > 0 && min == arr[i - 1])
            continue;
        
        for (int j = 0; j < N; j++)
        {
            if (arr[j] >= min && arr[j] <= min + K)
                cnt++;
        }

        ans = max(ans, cnt);
    }
    */

    // 솔직히 완전탐색인데 이게 더 교육적으로는 좋을듯
    for (int i = 1; i <= 10000; i++)
    {
        int cnt = 0;
        
        for (int j = 0; j < N; j++)
        {
            if (arr[j] >= i && arr[j] <= i + K)
                cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
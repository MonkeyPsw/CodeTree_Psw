#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[200000];
int bomb[1000001];
int ans = -1;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i <= 1000000; i++)
        bomb[i] = -1;

    for (int i = 0; i < N; i++)
    {
        if (bomb[arr[i]] != -1)
        {
            if (i - bomb[arr[i]] <= K)
                ans = max(ans, arr[i]);
        }

        bomb[arr[i]] = i;
    }

    cout << ans;

    return 0;
}

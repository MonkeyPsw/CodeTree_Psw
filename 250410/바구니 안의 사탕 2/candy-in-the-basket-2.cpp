#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, K;
int candy[100], pos[100];
int arr[101][101];
int ans = INT_MIN;

/* 아니 이렇게 쉬운 방법이 있었는데 내가 멀리 돌아갔구나
#include <iostream>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

int n, k;
int arr[MAX_NUM + 1];

int main() {
    // 입력
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x, a;
        cin >> a >> x;
        
        arr[x] += a;
    }
    
    // 모든 구간의 시작점을 잡아봅니다.
    int max_sum = 0;
    for(int i = 0; i <= MAX_NUM; i++) {
        // 해당 구간 내 원소의 합을 구합니다.
        int sum = 0;
        for(int j = i - k; j <= i + k; j++)
            if(j >= 0 && j <= MAX_NUM)
                sum += arr[j];
        
        // 최댓값을 구합니다.
        max_sum = max(max_sum, sum);
    }
                        
    cout << max_sum;
    return 0;
}
*/

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> candy[i] >> pos[i];

        for (int j = 0; j <= N; j++)
        {
            if (!arr[pos[i]][j])
            {
                arr[pos[i]][j] = candy[i];
                break;
            }
        }
    }

    for (int i = min(K, 100 - K); i < max(K, 100 - K); i++)
    {
        int sum = 0;

        for (int j = max(0, i - K); j <= min(100, i + K); j++)
        {
            for (int l = 0; l <= N; l++)
            {
                if (arr[j][l])
                    sum += arr[j][l];
                else
                    break;
            }
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
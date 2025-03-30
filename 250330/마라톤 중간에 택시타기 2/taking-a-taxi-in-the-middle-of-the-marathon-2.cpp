#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int n;
int x[100];
int y[100];
int length;
int ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n - 1; i++)
        length += abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);

    for (int i = 1; i < n - 1; i++)
    {
        int cnt = length;
        cnt -= abs(x[i - 1] - x[i]) + abs(y[i - 1] - y[i]);
        cnt -= abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        cnt += abs(x[i - 1] - x[i + 1]) + abs(y[i - 1] - y[i + 1]);

        ans = min(ans, cnt);
    }

    /* 이런식으로 할랬는데 몰루
    // 각 i번째 체크포인트를 건너 뛰었을 때의 거리를 구해줍니다.
	int ans = INT_MAX;
    for(int i = 1; i < n - 1; i++) {
		// 거리를 구합니다.
		int dist = 0;
		int prev_idx = 0;
    	for(int j = 1; j < n; j++) {
			if(j == i) continue;
        	dist += abs(x[prev_idx] - x[j]) + abs(y[prev_idx] - y[j]);
			prev_idx = j;
		}
		
		// 가능한 거리 중 최솟값을 구해줍니다.
		ans = min(ans, dist);
	}
    */

    cout << ans;

    return 0;
}
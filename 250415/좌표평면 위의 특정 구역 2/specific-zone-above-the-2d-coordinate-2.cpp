#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int x[100], y[100];
int ans = INT_MAX;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; i++)
    {
        int maxX = INT_MIN, minX = INT_MAX;
        int maxY = INT_MIN, minY = INT_MAX;

        for (int j = 0; j < N; j++)
        {
            if (j == i)
                continue;
            
            maxX = max(maxX, x[j]);
            minX = min(minX, x[j]);
            maxY = max(maxY, y[j]);
            minY = min(minY, y[j]);
        }

        ans = min(ans, (maxX - minX) * (maxY - minY));
        
        if (!ans)
            break;
    }

    cout << ans;

    return 0;
}
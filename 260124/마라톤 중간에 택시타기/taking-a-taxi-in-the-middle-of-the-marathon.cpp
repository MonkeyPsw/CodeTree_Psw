#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int x[100001], y[100001];
int distL[100001], distR[100001];
int ans = INT_MAX;

int CalDist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    distL[1] = 0;
    for (int i = 2; i <= n; i++)
        distL[i] = distL[i - 1] + CalDist(x[i - 1], y[i - 1], x[i], y[i]);

    distR[n] = 0;
    for (int i = n - 1; i >= 1; i--)
        distR[i] = distR[i + 1] + CalDist(x[i + 1], y[i + 1], x[i], y[i]);

    
    for (int i = 2; i <= n - 1; i++)
        ans = min(ans, distL[i - 1] + distR[i + 1] + CalDist(x[i - 1], y[i - 1], x[i + 1], y[i + 1]));

    cout << ans;

    /*
    for (int i = 1; i <= n; i++)
        cout << distL[i] << " ";

    cout << endl;

    for (int i = 1; i <= n; i++)
        cout << distR[i] << " ";
    */

    return 0;
}

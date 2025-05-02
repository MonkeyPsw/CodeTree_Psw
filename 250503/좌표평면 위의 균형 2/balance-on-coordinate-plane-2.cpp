#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int x[100], y[100];
int maxX = INT_MIN, maxY = INT_MIN;
int minX = INT_MAX, minY = INT_MAX;
int ans = INT_MAX;

// 1사분면 x보다 크고 y보다 큼
// 2사분면 x보다 작고 y보다 큼
// 3사분면 x보다 작고 y보다 작음
// 4사분면 x보다 크고 y보다 작음
int CalQ(int lineX, int lineY, int x, int y, int q)
{
    switch (q)
    {
        case 1: return (lineX < x && lineY < y);
        case 2: return (lineX > x && lineY < y);
        case 3: return (lineX > x && lineY > y);
        case 4: return (lineX < x && lineY > y);
    }

    return 0;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        maxX = max(maxX, x[i]);
        maxY = max(maxY, y[i]);
        minX = min(minX, x[i]);
        minY = min(minY, y[i]);
    }

    for (int lineX = minX + 1; lineX <= maxX - 1; lineX += 2)
    {
        for (int lineY = minY + 1; lineY <= maxY - 1; lineY += 2)
        {
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

            for (int i = 0; i < n; i++)
            {
                q1 += CalQ(lineX, lineY, x[i], y[i], 1);
                q2 += CalQ(lineX, lineY, x[i], y[i], 2);
                q3 += CalQ(lineX, lineY, x[i], y[i], 3);
                q4 += CalQ(lineX, lineY, x[i], y[i], 4);
            }

            int maxQ = max({q1, q2, q3, q4});

            ans = min(ans, maxQ);
        }
    }

    cout << ans;

    return 0;
}
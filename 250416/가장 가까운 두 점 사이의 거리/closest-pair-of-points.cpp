#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int x[100], y[100];
int ans = INT_MAX;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            int valX = x[i] - x[j];
            int valY = y[i] - y[j];

            sum = (valX * valX) + (valY * valY);
            
            ans = min(ans, sum);
        }
    }

    cout << ans;

    return 0;
}
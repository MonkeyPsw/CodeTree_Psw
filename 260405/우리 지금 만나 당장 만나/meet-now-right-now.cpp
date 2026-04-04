#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[100000];
int v[100000];
double ans;

bool IsPossible(double time)
{
    double minVal = -1e18;
    double maxVal = 1e18;

    for (int i = 0; i < n; i++)
    {
        minVal = max(minVal, x[i] - v[i] * time);
        maxVal = min(maxVal, x[i] + v[i] * time);
    }

    if (minVal <= maxVal)
        return true;
    
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double left = 0;
    double right = 1000000000;
    
    for (int i = 0; i < 100; i++)
    {
        double mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid;
            ans = mid;
        }
        else
            left = mid;
    }

    cout << fixed;
    cout.precision(4);

    cout << ans;

    return 0;
}

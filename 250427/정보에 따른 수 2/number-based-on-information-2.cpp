#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int T, a, b;
char c[100];
int x[100];
char line[1001];
int ans;

int DistanceS(int k)
{
    int s1 = 1000, s2 = 1000;

    for (int i = k; i >= 1; i--)
    {
        if (line[i] == 'S')
        {
            s1 = abs(i - k);
            break;
        }
    }

    for (int i = k; i <= 1000; i++)
    {
        if (line[i] == 'S')
        {
            s2 = abs(i - k);
            break;
        }
    }

    return min(s1, s2);
}

int DistanceN(int k)
{
    int n1 = 1000, n2 = 1000;

    for (int i = k; i >= 1; i--)
    {
        if (line[i] == 'N')
        {
            n1 = abs(i - k);
            break;
        }
    }

    for (int i = k; i <= 1000; i++)
    {
        if (line[i] == 'N')
        {
            n2 = abs(i - k);
            break;
        }
    }

    return min(n1, n2);
}

int main() {
    cin >> T >> a >> b;

    for (int i = 0; i < T; i++) {
        cin >> c[i] >> x[i];

        line[x[i]] = c[i];
    }

    for (int i = a; i <= b; i++)
    {
        int d1 = DistanceS(i);
        int d2 = DistanceN(i);

        if (d1 <= d2)
            ans++;
    }

    cout << ans;

    return 0;
}
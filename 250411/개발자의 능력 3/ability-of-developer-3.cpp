#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int abilities[6];
int ans = INT_MAX;

int GetDiff(int i, int j, int k)
{
    int sum1 = abilities[i] + abilities[j] + abilities[k];
    int sum2 = 0;
    for (int l = 0; l < 6; l++)
        sum2 += abilities[l];
    sum2 -= sum1;
    return abs(sum1 - sum2);
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
                ans = min(ans, GetDiff(i, j, k));
        }
    }

    cout << ans;

    return 0;
}
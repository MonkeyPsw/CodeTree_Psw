#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int ability[6];
int ans = INT_MAX;

int GetDiff(int i, int j, int k, int l)
{
    int sum1 = ability[i] + ability[j];
    int sum2 = ability[k] + ability[l];
    int allSum = 0;
    for (int n = 0; n < 6; n++)
        allSum += ability[n];
    allSum -= sum1;
    allSum -= sum2;
    return abs(max(max(sum1, sum2), allSum) - min(min(sum1, sum2), allSum));
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
    }

    //sort(ability, ability + 6);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                for (int l = 0; l < 6; l++)
                {
                    if (i == j || i == k || i == l ||
                        j == k || j == l || k == l)
                            continue;
                    ans = min(ans, GetDiff(i, j, k, l));
                }
            }
        }
    }

    cout << ans;

    return 0;
}
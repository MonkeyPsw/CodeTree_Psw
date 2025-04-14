#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[5];
int ans = INT_MAX;

int GetDiff(int i, int j, int k, int l)
{
    int sum1 = arr[i] + arr[j];
    int sum2 = arr[k] + arr[l];
    int allSum = 0;

    if (sum1 == sum2)
        return INT_MAX;

    for (int n = 0; n < 5; n++)
        allSum += arr[n];

    allSum -= sum1;
    allSum -= sum2;

    if (allSum == sum1 || allSum == sum2)
        return INT_MAX;

    return abs(max(max(sum1, sum2), allSum) - min(min(sum1, sum2), allSum));
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if (i == j || i == k || i == l ||
                        j == k || j == l || k == l)
                            continue;
                    ans = min(ans, GetDiff(i, j, k, l));
                }
            }
        }
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}
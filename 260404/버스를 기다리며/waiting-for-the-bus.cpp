#include <iostream>
#include <algorithm>

using namespace std;

int N, M, C;
int t[100000];
int ans;

bool IsPossible(int time)
{
    int busCnt = 1;
    int first = 0;

    for (int i = 0; i < N; i++)
    {
        if (t[i] - t[first] > time || i - first + 1 > C)
        {
            busCnt++;
            first = i;
        }
    }

    if (busCnt <= M)
        return true;
    
    return false;
}

int main() {
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t, t + N);

    int left = 0;
    int right = 1000000000;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}

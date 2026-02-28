#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int points[100000];
int st[100000], ed[100000];

int LowerBound(int num)
{
    int left = 0, right = n - 1;
    int idx = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (points[mid] >= num)
        {
            right = mid - 1;
            idx = min(idx, mid);
        }
        else
            left = mid + 1;
    }

    return idx;
}

int UpperBound(int num)
{
    int left = 0, right = n - 1;
    int idx = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (points[mid] > num)
        {
            right = mid - 1;
            idx = min(idx, mid);
        }
        else
            left = mid + 1;
    }

    return idx;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> st[i] >> ed[i];
    }

    sort(points, points + n);

    for (int i = 0; i < m; i++)
        cout << UpperBound(ed[i]) - LowerBound(st[i]) << endl;

    return 0;
}

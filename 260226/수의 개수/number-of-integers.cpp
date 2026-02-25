#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];

int LowerBound(int num)
{
    int left = 0, right = n - 1;
    int idx = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] >= num)
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

        if (arr[mid] > num)
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
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        cout << UpperBound(x) - LowerBound(x) << endl;
    }

    return 0;
}

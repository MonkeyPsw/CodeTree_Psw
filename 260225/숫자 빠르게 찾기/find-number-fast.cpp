#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int SearchIdx(int num)
{
    int idx = -2;
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == num)
        {
            idx = mid;
            break;
        }

        if (arr[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return idx + 1;
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

        cout << SearchIdx(x) << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int k, n;
int arr[10][20];
int ans;

int main() {
    cin >> k >> n;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    for (int a = 1; a <= n; a++)
    {
        int rank[21] = {};

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rank[arr[i][j]]++;
                if (arr[i][j] == a)
                    break;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!rank[i])
                ans++;
        }
    }

    cout << ans;

    return 0;
}
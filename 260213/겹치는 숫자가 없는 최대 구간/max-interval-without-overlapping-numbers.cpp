#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int num[100001];
int j, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (j + 1 <= n && num[arr[j + 1]] != 1)
        {
            num[arr[j + 1]]++;
            j++;
        }

        ans = max(ans, j - i + 1);

        num[arr[i]]--;
    }

    cout << ans;

    return 0;
}

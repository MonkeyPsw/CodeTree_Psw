#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, k;
int arr[100000];
unordered_map<int, int> ump;
int j, ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (j < n && ump[arr[j]] < k)
        {
            ump[arr[j]]++;
            j++;
        }

        ans = max(ans, j - i);
        
        ump[arr[i]]--;
    }

    cout << ans;

    return 0;
}

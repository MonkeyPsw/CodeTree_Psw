#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int arr[1000];
unordered_map<int, int> ump;
int ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int x = 2; x < n; x++)
    {
        for (int i = 0; i < x - 1; i++)
            ump[arr[i] + arr[x - 1]]++;

        if (ump.find(k - arr[x]) != ump.end())
            ans += ump[k - arr[x]];
    }

    cout << ans;

    return 0;
}

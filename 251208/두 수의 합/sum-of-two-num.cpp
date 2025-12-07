#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int arr[100000];
unordered_map<long long, int> iMap;
long long ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        ans += iMap[(long long)k - arr[i]];

        iMap[arr[i]]++;
    }

    cout << ans;

    return 0;
}

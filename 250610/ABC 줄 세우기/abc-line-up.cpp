#include <iostream>

using namespace std;

int n;
char arr[26];
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                ans++;
        }
    }

    cout << ans;

    return 0;
}
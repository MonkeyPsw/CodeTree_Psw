#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int numbers[100];
int ans = INT_MIN;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            int sum = numbers[i] + numbers[j];

            ans = max(ans, sum);
        }
    }

    cout << ans;

    return 0;
}
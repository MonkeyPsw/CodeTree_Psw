#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1[100000], x2[100000];
int line[200001];
int sum, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n; i++)
    {
        line[x1[i]] += 1;
        line[x2[i]] -= 1;
    }

    for (int i = 1; i <= 200000; i++)
    {
        sum += line[i];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}

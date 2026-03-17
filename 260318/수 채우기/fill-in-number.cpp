#include <iostream>

using namespace std;

int n;
int ans;

int main() {
    cin >> n;

    if (n == 1 || n == 3)
    {
        cout << -1;
        return 0;
    }

    ans += n / 5;
    n %= 5;

    if (n % 2 == 0)
        ans += n / 2;
    else
    {
        ans -= 1;
        n += 5;
        ans += n / 2;
    }

    cout << ans;

    return 0;
}

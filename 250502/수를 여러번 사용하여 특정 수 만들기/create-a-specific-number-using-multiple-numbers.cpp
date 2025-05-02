#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;
int ans;

int main() {
    cin >> A >> B >> C;

    for (int i = 0; i < C / A + 1; i++)
    {
        for (int j = 0; j < C / B + 1; j++)
        {
            if (A * i + B * j <= C)
                ans = max(ans, A * i + B * j);
        }
    }

    cout << ans;

    return 0;
}
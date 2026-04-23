#include <iostream>

using namespace std;

int n, q;
int dest[200000];
bool occupied[1048577];

int main() {
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        cin >> dest[i];
    }

    for (int i = 0; i < q; i++) {
        int x = dest[i];
        int cur = x;
        int ans = 0;

        while (cur >= 1) {
            if (occupied[cur]) {
                ans = cur;
            }
            cur /= 2;
        }

        cout << ans << endl;

        if (ans == 0) {
            occupied[x] = true;
        }
    }

    return 0;
}
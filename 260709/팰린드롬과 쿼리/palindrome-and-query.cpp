#include <iostream>
#include <string>

using namespace std;

int n, q;
string S;
int a[100000], b[100000];

int p[200005];

int main() {
    cin >> n >> q;
    cin >> S;

    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
    }

    string T = "#";
    for (int i = 0; i < n; i++) {
        T += S[i];
        T += "#";
    }

    int len = T.size();
    int center = 0;
    int right = 0;

    for (int i = 0; i < len; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < len &&
               T[i - p[i] - 1] == T[i + p[i] + 1]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    for (int i = 0; i < q; i++) {
        int l = a[i] - 1;
        int r = b[i] - 1;

        int center_idx = l + r + 1;
        int need = r - l + 1;

        if (p[center_idx] >= need) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
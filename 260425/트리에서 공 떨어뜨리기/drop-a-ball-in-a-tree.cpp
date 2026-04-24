#include <iostream>

using namespace std;

int n;
long long k;
int left_num[200001];
int right_num[200001];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> left_num[i] >> right_num[i];
    }

    cin >> k;

    int cur = 1;

    while (true) {
        int l = left_num[cur];
        int r = right_num[cur];

        if (l == -1 && r == -1) {
            cout << cur << endl;
            break;
        }

        if (l != -1 && r == -1) {
            cur = l;
        }
        else if (l == -1 && r != -1) {
            cur = r;
        }
        else {
            if (k % 2 == 1) {
                cur = l;
                k = (k + 1) / 2;
            }
            else {
                cur = r;
                k = k / 2;
            }
        }
    }

    return 0;
}
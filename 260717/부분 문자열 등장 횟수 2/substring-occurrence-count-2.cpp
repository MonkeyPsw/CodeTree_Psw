#include <iostream>
#include <string>

using namespace std;

string T;
int q;
string P[5];

int pi[100000];

int main() {
    cin >> T >> q;
    for (int i = 0; i < q; i++) {
        cin >> P[i];
    }

    for (int idx = 0; idx < q; idx++) {
        string pattern = P[idx];

        int n = T.size();
        int m = pattern.size();

        for (int i = 0; i < m; i++) {
            pi[i] = 0;
        }

        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (pattern[i] == pattern[j]) {
                pi[i] = ++j;
            }
        }

        int answer = 0;

        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && T[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (T[i] == pattern[j]) {
                if (j == m - 1) {
                    answer++;
                    j = pi[j];
                } else {
                    j++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}
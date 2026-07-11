#include <iostream>
#include <string>

using namespace std;

string text;
string pattern;

int pi[500000];

int main() {
    cin >> text;
    cin >> pattern;

    int n = text.size();
    int m = pattern.size();

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                cout << i - m + 1;
                return 0;
            } else {
                j++;
            }
        }
    }

    cout << -1;

    return 0;
}
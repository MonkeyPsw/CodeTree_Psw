#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string T;

int pi[100000];

int main() {
    cin >> T;

    int n = T.size();

    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && T[i] != T[j]) {
            j = pi[j - 1];
        }

        if (T[i] == T[j]) {
            pi[i] = ++j;
        }
    }

    string R = T;
    reverse(R.begin(), R.end());

    int answer = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && R[i] != T[j]) {
            j = pi[j - 1];
        }

        if (R[i] == T[j]) {
            j++;

            if (answer < j) {
                answer = j;
            }

            if (j == n) {
                j = pi[j - 1];
            }
        }
    }

    cout << answer;

    return 0;
}
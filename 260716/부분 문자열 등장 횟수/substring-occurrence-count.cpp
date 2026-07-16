#include <iostream>
#include <string>

using namespace std;

string T;
string P;

int pi[100000];

int main() {
    cin >> T;
    cin >> P;

    int n = T.size();
    int m = P.size();

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }

        if (P[i] == P[j]) {
            pi[i] = ++j;
        }
    }

    int answer = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) {
            j = pi[j - 1];
        }

        if (T[i] == P[j]) {
            if (j == m - 1) {
                answer++;
                j = pi[j];
            } else {
                j++;
            }
        }
    }

    cout << answer;

    return 0;
}
#include <iostream>
#include <string>

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

    cout << n - pi[n - 1];

    return 0;
}
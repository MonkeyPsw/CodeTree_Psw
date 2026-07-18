#include <iostream>
#include <string>

using namespace std;

int n;
string T;
string P;

int pi[100000];

int main() {
    cin >> n;
    cin >> T;
    cin >> P;

    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && T[i] != T[j]) {
            j = pi[j - 1];
        }

        if (T[i] == T[j]) {
            pi[i] = ++j;
        }
    }

    string text = P + P;
    text.pop_back();

    int answer = 0;

    for (int i = 0, j = 0; i < (int)text.size(); i++) {
        while (j > 0 && text[i] != T[j]) {
            j = pi[j - 1];
        }

        if (text[i] == T[j]) {
            if (j == n - 1) {
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
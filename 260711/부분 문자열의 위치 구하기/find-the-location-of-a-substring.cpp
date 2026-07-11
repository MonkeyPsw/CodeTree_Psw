#include <iostream>
#include <string>

#define MAX_N 500000

using namespace std;

string text;
string pattern;

int p[2] = {31, 37};
int mod[2] = {1000000007, 1000000009};

long long p_pow[2][MAX_N + 1];

int ToInt(char c) {
    return c - 'a' + 1;
}

int main() {
    cin >> text;
    cin >> pattern;

    int n = text.size();
    int l = pattern.size();

    for (int k = 0; k < 2; k++) {
        p_pow[k][0] = 1;

        for (int i = 1; i <= n; i++) {
            p_pow[k][i] = p_pow[k][i - 1] * p[k] % mod[k];
        }
    }

    long long pattern_hash[2] = {};
    long long text_hash[2] = {};

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < l; i++) {
            pattern_hash[k] = (pattern_hash[k] + ToInt(pattern[i]) * p_pow[k][l - 1 - i]) % mod[k];
            text_hash[k] = (text_hash[k] + ToInt(text[i]) * p_pow[k][l - 1 - i]) % mod[k];
        }
    }

    if (pattern_hash[0] == text_hash[0] && pattern_hash[1] == text_hash[1]) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n - l; i++) {
        for (int k = 0; k < 2; k++) {
            text_hash[k] = (text_hash[k] * p[k]
                            - ToInt(text[i - 1]) * p_pow[k][l]
                            + ToInt(text[i + l - 1])) % mod[k];

            if (text_hash[k] < 0) {
                text_hash[k] += mod[k];
            }
        }

        if (pattern_hash[0] == text_hash[0] && pattern_hash[1] == text_hash[1]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
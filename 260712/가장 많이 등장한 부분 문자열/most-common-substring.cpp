#include <iostream>
#include <string>
#include <unordered_map>

#define MAX_N 100000

using namespace std;

int l;
string S;

int p[2] = {31, 37};
int mod[2] = {1000000007, 1000000009};

long long p_pow[2][MAX_N + 1];

int ToInt(char c) {
    return c - 'a' + 1;
}

int main() {
    cin >> l >> S;

    int n = S.size();

    for (int k = 0; k < 2; k++) {
        p_pow[k][0] = 1;

        for (int i = 1; i <= n; i++) {
            p_pow[k][i] = p_pow[k][i - 1] * p[k] % mod[k];
        }
    }

    long long hash_value[2] = {};

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < l; i++) {
            hash_value[k] = (hash_value[k] + ToInt(S[i]) * p_pow[k][l - 1 - i]) % mod[k];
        }
    }

    unordered_map<long long, int> cnt;

    long long key = (hash_value[0] << 32) ^ hash_value[1];
    cnt[key]++;

    int answer = 1;

    for (int i = 1; i <= n - l; i++) {
        for (int k = 0; k < 2; k++) {
            hash_value[k] = (hash_value[k] * p[k]
                             - ToInt(S[i - 1]) * p_pow[k][l]
                             + ToInt(S[i + l - 1])) % mod[k];

            if (hash_value[k] < 0) {
                hash_value[k] += mod[k];
            }
        }

        key = (hash_value[0] << 32) ^ hash_value[1];
        cnt[key]++;

        if (answer < cnt[key]) {
            answer = cnt[key];
        }
    }

    cout << answer;

    return 0;
}
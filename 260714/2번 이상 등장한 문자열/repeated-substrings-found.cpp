#include <iostream>
#include <string>
#include <unordered_set>

#define MAX_N 100000

using namespace std;

string S;

int p[2] = {31, 37};
int mod[2] = {1000000007, 1000000009};

long long p_pow[2][MAX_N + 1];
long long prefix_hash[2][MAX_N + 1];

int ToInt(char c) {
    return c - 'a' + 1;
}

long long getHash(int k, int l, int r) {
    long long value = prefix_hash[k][r + 1] - prefix_hash[k][l] * p_pow[k][r - l + 1] % mod[k];

    if (value < 0) {
        value += mod[k];
    }

    return value;
}

bool existsDuplicate(int len) {
    if (len == 0) {
        return true;
    }

    unordered_set<long long> seen;

    int n = S.size();

    for (int i = 0; i + len - 1 < n; i++) {
        long long h0 = getHash(0, i, i + len - 1);
        long long h1 = getHash(1, i, i + len - 1);

        long long key = (h0 << 32) ^ h1;

        if (seen.find(key) != seen.end()) {
            return true;
        }

        seen.insert(key);
    }

    return false;
}

int main() {
    cin >> S;

    int n = S.size();

    for (int k = 0; k < 2; k++) {
        p_pow[k][0] = 1;

        for (int i = 1; i <= n; i++) {
            p_pow[k][i] = p_pow[k][i - 1] * p[k] % mod[k];
        }
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            prefix_hash[k][i + 1] = (prefix_hash[k][i] * p[k] + ToInt(S[i])) % mod[k];
        }
    }

    int left = 0;
    int right = n;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (existsDuplicate(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
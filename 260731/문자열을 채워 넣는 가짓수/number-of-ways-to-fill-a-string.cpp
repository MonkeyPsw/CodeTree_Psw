#include <iostream>
#include <string>

using namespace std;

const int MAX_NODE = 200000;
const int MOD = 1000000007;

string T;
int m;
string P[100000];

int trie[MAX_NODE + 1][26];
bool isEnd[MAX_NODE + 1];
int nodeCnt;

long long dp[5001];

int main() {
    cin >> T >> m;
    for (int i = 0; i < m; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < m; i++) {
        int cur = 0;

        for (char c : P[i]) {
            int next = c - 'a';

            if (trie[cur][next] == 0) {
                trie[cur][next] = ++nodeCnt;
            }

            cur = trie[cur][next];
        }

        isEnd[cur] = true;
    }

    int len = T.length();
    dp[0] = 1;

    for (int i = 0; i < len; i++) {
        if (dp[i] == 0) {
            continue;
        }

        int cur = 0;

        for (int j = i; j < len; j++) {
            int next = T[j] - 'a';

            if (trie[cur][next] == 0) {
                break;
            }

            cur = trie[cur][next];

            if (isEnd[cur]) {
                dp[j + 1] += dp[i];
                dp[j + 1] %= MOD;
            }
        }
    }

    cout << dp[len];

    return 0;
}
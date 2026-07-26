#include <iostream>
#include <string>

using namespace std;

const int MAX_NODE = 200000;

int n, m;
string words[100000];
string S;

int trie[MAX_NODE + 1][26];
int cnt[MAX_NODE + 1];
int nodeCnt;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cin >> S;

    for (int i = 0; i < n; i++) {
        int cur = 0;

        for (char c : words[i]) {
            int next = c - 'a';

            if (trie[cur][next] == 0) {
                trie[cur][next] = ++nodeCnt;
            }

            cur = trie[cur][next];
            cnt[cur]++;
        }
    }

    int cur = 0;
    bool found = true;

    for (int i = 0; i < m; i++) {
        int next = S[i] - 'a';

        if (!found || trie[cur][next] == 0) {
            found = false;
            cout << 0 << ' ';
        } else {
            cur = trie[cur][next];
            cout << cnt[cur] << ' ';
        }
    }

    return 0;
}
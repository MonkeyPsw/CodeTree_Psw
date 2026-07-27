#include <iostream>
#include <string>

using namespace std;

const int MAX_NODE = 200000;

int n;
string words[100000];

int trie[MAX_NODE + 1][26];
int cnt[MAX_NODE + 1];
int depth[MAX_NODE + 1];
int nodeCnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        int cur = 0;

        for (char c : words[i]) {
            int next = c - 'a';

            if (trie[cur][next] == 0) {
                trie[cur][next] = ++nodeCnt;
                depth[nodeCnt] = depth[cur] + 1;
            }

            cur = trie[cur][next];
            cnt[cur]++;

            answer = max(answer, 1LL * depth[cur] * cnt[cur]);
        }
    }

    cout << answer;

    return 0;
}
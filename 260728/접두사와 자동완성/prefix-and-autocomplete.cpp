#include <iostream>
#include <string>

using namespace std;

const int MAX_NODE = 200000;

int n;
string words[100000];

int trie[MAX_NODE + 1][26];
int childCnt[MAX_NODE + 1];
bool isEnd[MAX_NODE + 1];
int nodeCnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;

        for (char c : words[i]) {
            int next = c - 'a';

            if (trie[cur][next] == 0) {
                trie[cur][next] = ++nodeCnt;
                childCnt[cur]++;
            }

            cur = trie[cur][next];
        }

        isEnd[cur] = true;
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;
        int answer = 0;

        for (int j = 0; j < words[i].length(); j++) {
            int next = words[i][j] - 'a';

            if (j == 0 || isEnd[cur] || childCnt[cur] >= 2) {
                answer++;
            }

            cur = trie[cur][next];
        }

        cout << answer << ' ';
    }

    return 0;
}
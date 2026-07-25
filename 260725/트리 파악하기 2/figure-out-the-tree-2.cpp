#include <iostream>

using namespace std;

const int MAX_NODE = 15000;

int n;
char nodes[1000][15];
int k[1000];

int trie[MAX_NODE + 1][26];
int nodeCnt;

void PrintTree(int cur, int depth) {
    for (int i = 0; i < 26; i++) {
        if (trie[cur][i] == 0) {
            continue;
        }

        for (int j = 0; j < depth; j++) {
            cout << "--";
        }

        cout << char('A' + i) << '\n';

        PrintTree(trie[cur][i], depth + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> nodes[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;

        for (int j = 0; j < k[i]; j++) {
            int next = nodes[i][j] - 'A';

            if (trie[cur][next] == 0) {
                trie[cur][next] = ++nodeCnt;
            }

            cur = trie[cur][next];
        }
    }

    PrintTree(0, 0);

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

const int MAX_NODE = 100000;

int n;
string sequences[10000];

int trie[MAX_NODE + 1][10];
bool isEnd[MAX_NODE + 1];
int nodeCnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequences[i];
    }

    for (int i = 0; i < n; i++) {
        int node = 0;

        for (char c : sequences[i]) {
            // 기존의 더 짧은 수열이 현재 수열의 접두사인 경우
            if (isEnd[node]) {
                cout << 0;
                return 0;
            }

            int digit = c - '0';

            if (trie[node][digit] == 0) {
                trie[node][digit] = ++nodeCnt;
            }

            node = trie[node][digit];
        }

        // 현재 수열이 기존의 더 긴 수열의 접두사인 경우
        for (int digit = 0; digit < 10; digit++) {
            if (trie[node][digit] != 0) {
                cout << 0;
                return 0;
            }
        }

        // 완전히 같은 수열은 접두사로 판단하지 않음
        isEnd[node] = true;
    }

    cout << 1;

    return 0;
}
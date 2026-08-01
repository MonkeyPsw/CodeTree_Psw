#include <iostream>

using namespace std;

const int MAX_NODE = 150000 * 31 + 1;

int n;
int arr[150000];

int trie[MAX_NODE][2];
int nodeCnt;

void Insert(int value) {
    int cur = 0;

    for (int bit = 30; bit >= 0; bit--) {
        int next = (value >> bit) & 1;

        if (trie[cur][next] == 0) {
            trie[cur][next] = ++nodeCnt;
        }

        cur = trie[cur][next];
    }
}

int FindMaximumXor(int value) {
    int cur = 0;
    int result = 0;

    for (int bit = 30; bit >= 0; bit--) {
        int currentBit = (value >> bit) & 1;
        int oppositeBit = currentBit ^ 1;

        if (trie[cur][oppositeBit] != 0) {
            result |= (1 << bit);
            cur = trie[cur][oppositeBit];
        } else {
            cur = trie[cur][currentBit];
        }
    }

    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = 0;

    Insert(arr[0]);

    for (int i = 1; i < n; i++) {
        answer = max(answer, FindMaximumXor(arr[i]));
        Insert(arr[i]);
    }

    cout << answer;

    return 0;
}
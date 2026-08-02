#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_NODE = 1000000;
const int MAX_EDGE = 1000000;

int n;
string words[5000];

int head[MAX_NODE + 1];
int edgeTo[MAX_EDGE + 1];
int edgeNext[MAX_EDGE + 1];
char edgeChar[MAX_EDGE + 1];

int terminal[MAX_NODE + 1];
int best1[MAX_NODE + 1];
int best2[MAX_NODE + 1];

int nodeCnt;
int edgeCnt;

bool IsPalindrome(const string& word, int left, int right) {
    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int FindChild(int node, char c) {
    for (int edge = head[node]; edge != 0; edge = edgeNext[edge]) {
        if (edgeChar[edge] == c) {
            return edgeTo[edge];
        }
    }

    return 0;
}

int AddChild(int node, char c) {
    int child = ++nodeCnt;
    int edge = ++edgeCnt;

    edgeTo[edge] = child;
    edgeChar[edge] = c;
    edgeNext[edge] = head[node];
    head[node] = edge;

    return child;
}

void AddCandidate(int node, int index) {
    if (best1[node] == index || best2[node] == index) {
        return;
    }

    if (best1[node] == -1 ||
        words[index].length() > words[best1[node]].length()) {
        best2[node] = best1[node];
        best1[node] = index;
    } else if (best2[node] == -1 ||
               words[index].length() > words[best2[node]].length()) {
        best2[node] = index;
    }
}

void InsertWord(int index) {
    const string& word = words[index];
    int cur = 0;

    for (int i = (int)word.length() - 1; i >= 0; i--) {
        if (IsPalindrome(word, 0, i)) {
            AddCandidate(cur, index);
        }

        int next = FindChild(cur, word[i]);

        if (next == 0) {
            next = AddChild(cur, word[i]);
        }

        cur = next;
    }

    terminal[cur] = index;
    AddCandidate(cur, index);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    fill(terminal, terminal + MAX_NODE + 1, -1);
    fill(best1, best1 + MAX_NODE + 1, -1);
    fill(best2, best2 + MAX_NODE + 1, -1);

    for (int i = 0; i < n; i++) {
        InsertWord(i);
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        const string& word = words[i];
        int cur = 0;
        bool possible = true;

        for (int j = 0; j < (int)word.length(); j++) {
            int other = terminal[cur];

            if (other != -1 && other != i &&
                IsPalindrome(word, j, word.length() - 1)) {
                answer = max(answer,
                             (int)word.length() +
                             (int)words[other].length());
            }

            cur = FindChild(cur, word[j]);

            if (cur == 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            int other = best1[cur];

            if (other == i) {
                other = best2[cur];
            }

            if (other != -1) {
                answer = max(answer,
                             (int)word.length() +
                             (int)words[other].length());
            }
        }
    }

    cout << answer;

    return 0;
}
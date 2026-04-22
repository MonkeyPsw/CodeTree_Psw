#include <iostream>

using namespace std;

int n;
char leftChild[26], rightChild[26];

void preorder(char cur) {
    if (cur == '.') return;
    cout << cur;
    preorder(leftChild[cur - 'A']);
    preorder(rightChild[cur - 'A']);
}

void inorder(char cur) {
    if (cur == '.') return;
    inorder(leftChild[cur - 'A']);
    cout << cur;
    inorder(rightChild[cur - 'A']);
}

void postorder(char cur) {
    if (cur == '.') return;
    postorder(leftChild[cur - 'A']);
    postorder(rightChild[cur - 'A']);
    cout << cur;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        char x, l, r;
        cin >> x >> l >> r;
        leftChild[x - 'A'] = l;
        rightChild[x - 'A'] = r;
    }

    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');

    return 0;
}
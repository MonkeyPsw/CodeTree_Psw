#include <iostream>
#include <vector>

#define MAX_N 1024

using namespace std;

int K;
vector<int> inorder_traversal;

int n;
int tree_num[MAX_N];
int idx = 0;

void inorder_fill(int node) {
    if (node > n) return;

    inorder_fill(node * 2);
    tree_num[node] = inorder_traversal[idx];
    idx++;
    inorder_fill(node * 2 + 1);
}

int main() {
    cin >> K;

    inorder_traversal.resize((1 << K) - 1);
    for (int i = 0; i < (1 << K) - 1; i++) {
        cin >> inorder_traversal[i];
    }

    n = (1 << K) - 1;

    inorder_fill(1);

    for (int depth = 1; depth <= K; depth++) {
        int start = 1 << (depth - 1);
        int end = (1 << depth) - 1;

        for (int i = start; i <= end; i++) {
            cout << tree_num[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
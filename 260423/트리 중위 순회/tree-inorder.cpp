#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> inorder_traversal;
vector<int> depth_nodes[11];

void dfs(int left, int right, int depth) {
    if (left > right) return;

    int mid = (left + right) / 2;
    depth_nodes[depth].push_back(inorder_traversal[mid]);

    dfs(left, mid - 1, depth + 1);
    dfs(mid + 1, right, depth + 1);
}

int main() {
    cin >> K;

    inorder_traversal.resize((1 << K) - 1);
    for (int i = 0; i < (1 << K) - 1; i++) {
        cin >> inorder_traversal[i];
    }

    dfs(0, (1 << K) - 2, 1);

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < depth_nodes[i].size(); j++) {
            cout << depth_nodes[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int n;
int inorder[100000];
int postorder[100000];
int in_pos[100001];

void PreOrder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end) return;

    int root = postorder[post_end];
    int root_pos = in_pos[root];
    int left_size = root_pos - in_start;

    cout << root << ' ';

    PreOrder(in_start, root_pos - 1, post_start, post_start + left_size - 1);
    PreOrder(root_pos + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        in_pos[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    PreOrder(0, n - 1, 0, n - 1);

    return 0;
}
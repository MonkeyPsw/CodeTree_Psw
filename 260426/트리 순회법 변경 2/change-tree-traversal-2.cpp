#include <iostream>

using namespace std;

int n;
int pre_order[100000];
int in_order[100000];
int in_pos[100001];

void PostOrder(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end) return;

    int root = pre_order[pre_start];
    int root_pos = in_pos[root];
    int left_size = root_pos - in_start;

    PostOrder(pre_start + 1, pre_start + left_size, in_start, root_pos - 1);
    PostOrder(pre_start + left_size + 1, pre_end, root_pos + 1, in_end);
    cout << root << ' ';
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> pre_order[i];

    for (int i = 0; i < n; i++) {
        cin >> in_order[i];
        in_pos[in_order[i]] = i;
    }

    PostOrder(0, n - 1, 0, n - 1);

    return 0;
}
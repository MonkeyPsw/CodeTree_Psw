#include <iostream>

using namespace std;

int n;
int pre_order[10000];

void PostOrder(int left, int right) {
    if (left > right) return;

    int root = pre_order[left];

    int mid = left + 1;
    while (mid <= right && pre_order[mid] < root) {
        mid++;
    }

    PostOrder(left + 1, mid - 1);
    PostOrder(mid, right);
    cout << root << endl;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pre_order[i];
    }

    PostOrder(0, n - 1);

    return 0;
}
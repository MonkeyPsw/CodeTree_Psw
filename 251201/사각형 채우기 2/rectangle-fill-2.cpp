#include <iostream>

using namespace std;

int n;
int box[1001];

int main() {
    cin >> n;

    box[1] = 1;
    box[2] = 3;

    for (int i = 3; i <= n; i++)
        box[i] = (box[i - 1] + box[i - 2] * 2) % 10007;

    cout << box[n];

    return 0;
}

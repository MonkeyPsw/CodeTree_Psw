#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_N = 100000;
int n;
int arr[MAX_N];
unordered_set<int> ust;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        ust.insert(arr[i]);
    }

    cout << ust.size();

    return 0;
}

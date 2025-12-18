#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];
unordered_set<int> ust;
bool isSame = true;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];

        ust.insert(arr1[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (ust.find(arr2[i]) == ust.end())
            cout << 0;
        else
            cout << 1;
        cout << " ";
    }

    return 0;
}

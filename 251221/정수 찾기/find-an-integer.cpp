#include <iostream>
#include <unordered_set>

using namespace std;

int n;
int m;
int a[100000];
int b[100000];
unordered_set<int> ust;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        ust.insert(a[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (ust.find(b[i]) != ust.end())
            cout << 1;
        else
            cout << 0;
            
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int A[200000];
int B[200000];
unordered_set<int> ust;
int cnt;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];

        ust.insert(A[i]);
    }

    for (int i = 0; i < m; i++) cin >> B[i];

    for (int i = 0; i < m; i++)
    {
        if (ust.find(B[i]) != ust.end())
            cnt++;
    }

    cout << n + m - cnt * 2;

    return 0;
}

#include <iostream>

using namespace std;

int n, m;
int A[100000];
int B[100000];
int cur;
bool isSub = true;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < m; i++)
    {
        while (cur < n && A[cur] != B[i])
            cur++;

        if (cur == n)
        {
            isSub = false;
            break;
        }
        else
            cur++;
    }

    if (isSub)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

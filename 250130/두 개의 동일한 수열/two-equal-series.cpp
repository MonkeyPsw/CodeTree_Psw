#include <iostream>
#include <algorithm>

using namespace std;

int n;
int A[100];
int B[100];

bool IsSame(int x[], int y[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (x[i] != y[i])
            return false;
    }
    return true;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A, A + n);
    sort(B, B + n);

    cout << (IsSame(A, B, n) ? "Yes" : "No");

    return 0;
}
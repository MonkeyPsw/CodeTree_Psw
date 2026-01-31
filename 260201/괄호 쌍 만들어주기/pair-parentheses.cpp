#include <iostream>
#include <string>

using namespace std;

string A;
int close[100000];
long long ans;

int main() {
    cin >> A;

    for (int i = A.length() - 2; i >= 0; i--)
    {
        close[i] = close[i + 1];

        if (A[i] == ')' && A[i + 1] == ')')
            close[i]++;
    }

    for (int i = 1; i < A.length(); i++)
    {
        if (A[i] == '(' && A[i - 1] == '(')
            ans += close[i + 1];
    }

    cout << ans;

    return 0;
}
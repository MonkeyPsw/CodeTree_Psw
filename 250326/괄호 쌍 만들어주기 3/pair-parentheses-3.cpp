#include <iostream>
#include <string>

using namespace std;

string A;
int cnt;

int main() {
    cin >> A;

    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
        {
            for (int j = i + 1; j < A.length(); j++)
                if (A[j] == ')')
                    cnt++;
        }
    }

    cout << cnt;

    return 0;
}
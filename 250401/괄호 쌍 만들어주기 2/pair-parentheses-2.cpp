#include <iostream>
#include <string>

using namespace std;

string A;
int cnt;

int main() {
    cin >> A;

    for (int i = 0; i < A.length() - 1; i++)
    {
        if (A[i] == '(' && A[i + 1] == '(')
        {
            for (int j = i + 1; j < A.length() - 1; j++)
            {
                if (A[j] == ')' && A[j + 1] == ')')
                    cnt++;
            }
        }
    }

    /* 이렇게 해도 정답이더라
    for (int i = 0; i < A.length(); i++)
    {
        for (int j = i + 2; j < A.length(); j++)
        {
            if (A[i] == '(' && A[i + 1] == '(')
            {
                if (A[j] == ')' && A[j + 1] == ')')
                    cnt++;
            }
        }
    }
    */

    cout << cnt;

    return 0;
}
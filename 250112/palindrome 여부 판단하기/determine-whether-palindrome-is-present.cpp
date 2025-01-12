#include <iostream>
#include <string>

using namespace std;

string A;

void IsPalindrome(string &s)
{
    string rev_s;

    for (int i = s.length() - 1; i >= 0; i--)
        rev_s += s[i];

    if (s == rev_s)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    cin >> A;

    IsPalindrome(A);

    return 0;
}
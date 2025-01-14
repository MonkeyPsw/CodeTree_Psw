#include <iostream>
#include <string>

using namespace std;

string A;

bool IsManyAPB(string s)
{
    char c = s[0];

    for (int i = 1; i < s.length(); i++)
    {
        if (c != s[i])
            return true;
    }

    return false;
}

int main() {
    cin >> A;

    cout << (IsManyAPB(A) ? "Yes" : "No");

    return 0;
}
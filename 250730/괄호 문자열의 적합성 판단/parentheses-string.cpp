#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> s;

bool CheckStr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else
        {
            if (s.empty())
                return false;
            s.pop();
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

int main() {
    cin >> str;

    cout << (CheckStr(str) ? "Yes" : "No");

    return 0;
}

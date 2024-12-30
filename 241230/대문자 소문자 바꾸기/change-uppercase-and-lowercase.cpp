#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z'))
            cout << (char)tolower(str[i]);
        else if ((str[i] >= 'a' && str[i] <= 'z'))
            cout << (char)toupper(str[i]);
    }

    return 0;
}
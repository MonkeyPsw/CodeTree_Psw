#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        // if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        if (isalpha(str[i]))
            cout << (char)toupper(str[i]);
    }

    return 0;
}
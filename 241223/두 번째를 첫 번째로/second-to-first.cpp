#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cin >> str;

    char letter = str[1];
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == letter)
            str[i] = str[0];
    }

    cout << str;

    return 0;
}
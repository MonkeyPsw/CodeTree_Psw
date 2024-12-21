#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cin >> str;

    char c1 = str[0];
    char c2 = str[1];

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c1)
            str[i] = c2;
        else if (str[i] == c2)
            str[i] = c1;
    }

    cout << str;

    return 0;
}
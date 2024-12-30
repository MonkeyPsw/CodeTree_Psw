#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cin >> str;

    while (str != "END")
    {
        string str_Rev;
        for (int i = str.length() - 1; i >= 0; i--)
            str_Rev += str[i];
        str = str_Rev;

        cout << str << endl;
        
        cin >> str;
    }

    return 0;
}
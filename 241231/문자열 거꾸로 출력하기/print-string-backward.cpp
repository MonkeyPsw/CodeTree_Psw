#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    while (true)
    {
        cin >> str;

        if (str == "END")
            break;

        for (int i = str.length() - 1; i >= 0; i--)
            cout << str[i];

        cout << endl;
    }

    /* 좀 안 이쁘긴 하네 근데 최대 10번이었구나
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
    */

    return 0;
}
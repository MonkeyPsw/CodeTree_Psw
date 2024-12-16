#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "ee", str2 = "ab";
    string myStr;
    bool isStr1 = false, isStr2 = false;

    cin >> myStr;

    for (int i = 0; i < myStr.length() - 1; i ++)
    {
        if (myStr.substr(i, 2) == str1)
            isStr1 = true;
        if (myStr.substr(i, 2) == str2)
            isStr2 = true;
    }

    cout << (isStr1 ? "Yes" : "No") << " " << (isStr2 ? "Yes" : "No");

    return 0;
}
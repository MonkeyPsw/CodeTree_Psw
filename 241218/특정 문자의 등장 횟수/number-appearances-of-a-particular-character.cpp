#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "ee", str2 = "eb";
    int cnt1 = 0, cnt2 = 0;
    string myStr;

    cin >> myStr;

    for (int i = 0; i < myStr.length() - 1; i++)
    {
        if (myStr.substr(i, 2) == str1)
            cnt1++;
        if (myStr.substr(i, 2) == str2)
            cnt2++;
    }

    cout << cnt1 << " " << cnt2;

    return 0;
}
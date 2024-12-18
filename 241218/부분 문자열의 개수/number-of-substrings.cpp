#include <iostream>
#include <string>
using namespace std;

int main() {
    string strA, strB;
    int cnt = 0;

    cin >> strA >> strB;

    for (int i = 0; i < strA.length() - 1; i++)
    {
        if (strA.substr(i, 2) == strB)
            cnt++;
    }

    cout << cnt;

    return 0;
}
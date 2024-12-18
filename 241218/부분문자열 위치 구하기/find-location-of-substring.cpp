#include <iostream>
#include <string>
using namespace std;

int main() {
    string inStr, outStr;
    int idx = -1;

    cin >> inStr >> outStr;

    if (inStr.find(outStr) != string::npos)
        idx = inStr.find(outStr);

    cout << idx;

    return 0;
}
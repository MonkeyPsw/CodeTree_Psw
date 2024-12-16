#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char c;
    int idx = -1;

    cin >> str >> c;

    if (str.find(c) != string::npos)
        idx = str.find(c);

    if (idx > -1)
        cout << idx;
    else
        cout << "No";

    return 0;
}
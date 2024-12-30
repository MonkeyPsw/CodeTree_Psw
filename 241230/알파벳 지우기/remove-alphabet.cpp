#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    string aStr, bStr;

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        if (isdigit(a[i]))
            aStr += a[i];
    }

    for (int i = 0; i < b.length(); i++)
    {
        if (isdigit(b[i]))
            bStr += b[i];
    }

    cout << stoi(aStr) + stoi(bStr);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int n = -1;

    cin >> a >> b;

    int len = a.length();

    for (int i = 0; i < len; i++)
    {
        if (a == b)
        {
            n = i;
            break;
        }
        else
            a = a.substr(len - 1, 1) + a.substr(0, len - 1);
    }

    cout << n;

    return 0;
}
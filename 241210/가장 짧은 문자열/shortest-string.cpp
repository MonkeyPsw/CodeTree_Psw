#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    int a, b, c;
    a = str1.length();
    b = str2.length();
    c = str3.length();

    if (a >= b)
    {
        if (a >= c)
        {
            if (b >= c)
                cout << a - c;
            else
                cout << a - b;
        }
        else
            cout << c - b;
    }
    else
    {
        if (b >= c)
        {
            if (a >= c)
                cout << b - c;
            else
                cout << b - a;
        }
        else
            cout << c - a;
    }

    return 0;
}
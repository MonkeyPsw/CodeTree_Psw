#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int a_int, b_int;

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        a_int = stoi(a);
        if (!isdigit(a[i]))
            a_int = stoi(a.substr(0, i));
    }

    for (int i = 0; i < b.length(); i++)
    {
        b_int = stoi(b);
        if (!isdigit(b[i]))
            b_int = stoi(b.substr(0, i));
    }

    cout << a_int + b_int;

    return 0;
}
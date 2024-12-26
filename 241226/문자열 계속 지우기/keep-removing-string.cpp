#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    bool isDel = true;

    cin >> a >> b;

    while (isDel)
    {
        int idx = -1;

        if (a.find(b) != string::npos)
        {
            idx = a.find(b);
            a.erase(idx, b.length());
        }
        else
            isDel = false;
    }

    cout << a;

    return 0;
}
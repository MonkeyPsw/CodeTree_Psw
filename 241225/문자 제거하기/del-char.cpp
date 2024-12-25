#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;

    cin >> str;

    while (str.length() > 1)
    {
        cin >> n;

        if (n < str.length())
            str.erase(n, 1);
        else
            str.erase(str.length() - 1, 1);
        
        cout << str << endl;
    }

    return 0;
}
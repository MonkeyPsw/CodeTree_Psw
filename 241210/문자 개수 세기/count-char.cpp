#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char c;
    int cnt = 0;

    getline(cin, str);
    cin >> c;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
            cnt++;
    }
    cout << cnt;
    return 0;
}
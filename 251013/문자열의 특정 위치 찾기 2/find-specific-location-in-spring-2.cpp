#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[5] = {"apple", "banana", "grape", "blueberry", "orange"};
    char c;
    int cnt = 0;

    cin >> c;

    for (int i = 0; i < 5; i++)
    {
        if (s[i][2] == c || s[i][3] == c)
        {
            cnt++;
            cout << s[i] << endl;
        }
    }

    cout << cnt;

    return 0;
}
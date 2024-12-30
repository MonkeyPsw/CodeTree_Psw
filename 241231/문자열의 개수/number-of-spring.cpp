#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string str[200];

    while (true)
    {
        cin >> str[cnt];

        if (str[cnt] == "0")
            break;

        cnt++;
    }

    cout << cnt << endl;

    for (int i = 0; i < cnt; i++)
    {
        if (i % 2 == 0)
            cout << str[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, cnt = 0;
    string a;

    cin >> n >> a;

    for (int i = 0; i < n; i++)
    {
        string str;

        cin >> str;

        if (str == a)
            cnt++;
    }

    cout << cnt;

    return 0;
}
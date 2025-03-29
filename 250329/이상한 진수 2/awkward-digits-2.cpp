#include <iostream>

using namespace std;

string a;
int num;
bool isAllOne = true;

int main() {
    cin >> a;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '0')
        {
            a[i] = '1';
            isAllOne = false;
            break;
        }
    }

    if (isAllOne)
        a[a.length() - 1] = '0';

    for (int i = 0; i < a.length(); i++)
        num = num * 2 + (a[i] - '0');

    cout << num;

    return 0;
}
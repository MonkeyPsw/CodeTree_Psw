#include <iostream>
using namespace std;

int main() {
    char ch;

    cin >> ch;

    if (ch == 'z')
        ch -= 25;
    else
        ch++;

    cout << ch;

    return 0;
}
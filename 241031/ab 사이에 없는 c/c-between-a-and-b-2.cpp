#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    bool isC = true;
    cin >> a >> b >> c;
    for (int i = a; i <= b; i++)
    {
        if (i % c != 0)
            isC = false;
    }
    if (!isC)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
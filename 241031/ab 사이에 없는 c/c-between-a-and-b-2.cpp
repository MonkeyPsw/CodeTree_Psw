#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    bool isNotC = true;
    cin >> a >> b >> c;
    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
            isNotC = false;
    }
    if (isNotC)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
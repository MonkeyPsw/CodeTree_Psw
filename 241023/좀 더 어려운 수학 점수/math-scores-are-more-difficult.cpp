#include <iostream>
using namespace std;

int main() {
    int aMath, aEng;
    int bMath, bEng;

    cin >> aMath >> aEng;
    cin >> bMath >> bEng;

    if (aMath > bMath || aMath == bMath && aEng > bEng)
        cout << 'A';
    else
        cout << 'B';

    return 0;
}
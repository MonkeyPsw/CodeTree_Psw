#include <iostream>
using namespace std;

int main() {
    int mScore, fScore;
    cin >> mScore >> fScore;

    if (mScore >= 90 && fScore >= 95)
        cout << 100000;
    else if (mScore >= 90 && fScore >= 90)
        cout << 50000;
    else
        cout << 0;
    return 0;
}
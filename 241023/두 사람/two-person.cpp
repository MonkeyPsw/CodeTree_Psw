#include <iostream>
using namespace std;

int main() {
    int aAge, bAge;
    char aSex, bSex;

    cin >> aAge >> aSex;
    cin >> bAge >> bSex;

    cout << ((aAge >= 19 && aSex == 'M') || (bAge >= 19 && bSex == 'M'));

    return 0;
}
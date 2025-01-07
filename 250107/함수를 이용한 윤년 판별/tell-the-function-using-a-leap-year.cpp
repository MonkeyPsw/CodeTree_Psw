#include <iostream>

using namespace std;

int y;

bool IsLeapYear(int n)
{
    if (n % 4 != 0)
        return false;
    if (n % 100 == 0 && n % 400 != 0)
        return false;
    return true;
    
}

int main() {
    cin >> y;

    cout << (IsLeapYear(y) ? "true" : "false");

    return 0;
}
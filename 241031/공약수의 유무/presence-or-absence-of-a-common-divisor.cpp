#include <iostream>
using namespace std;

int main() {
    int a, b;
    bool isCommon = false;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (1920 % i == 0 && 2880 % i == 0)
            isCommon = true;
    }
    cout << isCommon;
    return 0;
}
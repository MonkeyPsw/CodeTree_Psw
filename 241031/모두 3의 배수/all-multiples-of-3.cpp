#include <iostream>
using namespace std;

int main() {
    int n;
    bool isThree = true;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        if (n % 3 != 0)
            isThree = false;
    }
    cout << isThree;
    return 0;
}
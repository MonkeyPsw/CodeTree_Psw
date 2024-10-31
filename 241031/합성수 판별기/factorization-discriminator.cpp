#include <iostream>
using namespace std;

int main() {
    int n;
    bool isComp = false;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            isComp = true;
    }
    if (isComp)
        cout << 'C';
    else
        cout << 'N';
    return 0;
}
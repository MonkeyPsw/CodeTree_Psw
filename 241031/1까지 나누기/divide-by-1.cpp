#include <iostream>
using namespace std;

int main() {
    int i = 1, n;
    cin >> n;
    while (n > 1)
    {
        n /= i;
        if (n <= 1)
        {
            cout << i;
            break;
        }
        i++;
    }
    return 0;
}
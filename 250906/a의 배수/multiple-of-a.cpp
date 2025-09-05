#include <iostream>
using namespace std;

int main() {
    int N, a, i = 1;

    cin >> N >> a;

    while (i <= N)
    {
        if (i % a == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
            
        i++;
    }

    return 0;
}
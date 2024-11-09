#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "  ";
        for (int j = n - i; j > 0; j--)
            cout << cnt++ % 9 + 1 << " ";
        cout << endl;
    }
    return 0;
}
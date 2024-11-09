#include <iostream>
using namespace std;

int main() {
    int n, cnt = 65;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << (char)cnt++;
        cout << endl;
    }
    return 0;
}
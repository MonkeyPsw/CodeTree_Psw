#include <iostream>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cnt % 10 == 0) cnt++;
            cout << cnt++ % 10;
        }
        cout << endl;
    }
    return 0;
}
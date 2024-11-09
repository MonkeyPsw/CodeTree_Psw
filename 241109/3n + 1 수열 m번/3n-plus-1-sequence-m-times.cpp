#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        cin >> m;
        while (m > 1)
        {
            if (m % 2 == 0)
                m /= 2;
            else
                m = m * 3 + 1;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cnt % 8 + 1 << " ";
            cnt += 2;
            /* cnt를 2로 선언하면
            if (cnt >= 10) cnt -= 8;
            cout << cnt << " ";
            cnt += 2;
            */
        }
        cout << endl;
    }
    return 0;
}
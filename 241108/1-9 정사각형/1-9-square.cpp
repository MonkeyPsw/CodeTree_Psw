#include <iostream>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << (cnt++ % 9) + 1; 처음에 cnt 0으로 시작하면 한줄로도 가능
            if (cnt % 10 == 0) cnt++;
            cout << cnt++ % 10;
        }
        cout << endl;
    }
    return 0;
}
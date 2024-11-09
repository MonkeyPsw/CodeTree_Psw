#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int divCnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                divCnt++;
        }
        if (divCnt == 2)
            cout << i << " ";
    }
    return 0;
}
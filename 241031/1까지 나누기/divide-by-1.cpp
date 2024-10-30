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
            break; // 생각해보니 while에는 break 어차피 없어도 되네
        }
        i++;
    }
    /*
    for(int i = 1; i <= 100; i++) {
        if(n <= 1) {
            cout << cnt;
            break;
        }
        n /= i;
        cnt++;
    }
    */
    return 0;
}
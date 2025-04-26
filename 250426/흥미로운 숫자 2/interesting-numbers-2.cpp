#include <iostream>

using namespace std;

int X, Y;
int ans;

int main() {
    cin >> X >> Y;

    for (int i = X; i <= Y; i++)
    {
        int num = i;
        int tmp[10] = {};
        int cnt = 0;

        while (num)
        {
            tmp[num % 10]++;

            cnt++;
            
            num /= 10;
        }

        for (int j = 0; j < 10; j++)
        {
            if (tmp[j] == cnt - 1)
                ans++;
        }
    }

    cout << ans;

    return 0;
}
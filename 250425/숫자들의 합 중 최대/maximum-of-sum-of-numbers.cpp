#include <iostream>
#include <algorithm>

using namespace std;

int X, Y;
int ans;

int main() {
    cin >> X >> Y;

    for (int i = X; i <= Y; i++)
    {
        int num = i;
        int sum = 0;
        
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
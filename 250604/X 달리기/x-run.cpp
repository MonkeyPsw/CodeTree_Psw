#include <iostream>
#include <cmath>

using namespace std;

int X;
int ans;

/* 뭔가 재귀로 쌈박하게 될거같았어
int CalTime(int n)
{
    int i = sqrt(n);
    int cnt = 0;

    if (n == i * i)
    {
        cnt += i * 2 - 1;
        return cnt;
    }

    if ((n - 1) == i * i)
    {
        cnt += i * 2;
        return cnt;
    }

    cnt += i * 2 - 1;
    cnt += CalTime(n - (i * i));

    return cnt;
}
*/

int main() {
    cin >> X;

    int speed = sqrt(X);

    ans += speed * 2 - 1;

    X -= speed * speed;

    while (X > 0)
    {
        ans++;
        X -= speed;
    }

    cout << ans;

    return 0;
}
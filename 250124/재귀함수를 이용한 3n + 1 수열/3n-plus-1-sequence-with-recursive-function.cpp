#include <iostream>

using namespace std;

int n;
int cnt;

/* 원래 전역 안쓰고 이렇게 하는게 멋지긴한데
// a가 3n + 1 수열을 총 몇번 반복해야 1이 되는지 반환합니다.
int CountNumber(int a) {
    if(a == 1)
        return 0;

    if(a % 2 == 0)
        return CountNumber(a / 2) + 1;
    else
        return CountNumber(3 * a + 1) + 1;
}
*/

int MakeNumber(int x)
{
    if (x == 1)
        return cnt;
    
    cnt++;

    if (x % 2 == 0)
        return MakeNumber(x / 2);
    else
        return MakeNumber(x * 3 + 1);
}

int main() {
    cin >> n;

    cout << MakeNumber(n);

    return 0;
}
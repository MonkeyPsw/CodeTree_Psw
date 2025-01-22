#include <iostream>

using namespace std;

int n;
int cnt;

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
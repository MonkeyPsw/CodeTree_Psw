#include <iostream>

using namespace std;

int N;
int cnt;

int MakeNumber(int n)
{
    if (n == 1)
        return cnt;

    cnt++;

    if (n % 2 == 0)
        return MakeNumber(n / 2);
    else
        return MakeNumber(n / 3);
}

int main() {
    cin >> N;

    cout << MakeNumber(N);

    return 0;
}
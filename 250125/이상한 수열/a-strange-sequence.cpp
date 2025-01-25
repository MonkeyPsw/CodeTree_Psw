#include <iostream>

using namespace std;

int N;

int MakeNumber(int n)
{
    if (n == 1 || n == 2)
        return n;

    return MakeNumber(n / 3) + MakeNumber(n - 1);
}

int main() {
    cin >> N;

    cout << MakeNumber(N);

    return 0;
}
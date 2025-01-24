#include <iostream>

using namespace std;

int N;

int MakeNumber(int n)
{
    if (n == 1)
        return 2;
    if (n == 2)
        return 4;

    return MakeNumber(n - 1) * MakeNumber(n - 2) % 100;
}

int main() {
    cin >> N;

    cout << MakeNumber(N);

    return 0;
}
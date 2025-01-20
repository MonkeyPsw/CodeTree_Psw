#include <iostream>

using namespace std;

int N;

int Fact(int n)
{
    if (n < 2)
        return 1;

    return n * Fact(n - 1);
}

int main() {
    cin >> N;

    cout << Fact(N);

    return 0;
}
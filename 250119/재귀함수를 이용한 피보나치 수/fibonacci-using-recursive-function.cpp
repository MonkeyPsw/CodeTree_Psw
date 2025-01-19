#include <iostream>

using namespace std;

int N;

int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    cin >> N;

    cout << Fibonacci(N);

    return 0;
}
#include <iostream>

using namespace std;

int N;
int fibo[46];
int memo[46];

void InitMemo()
{
    for (int i = 1; i <= 46; i++)
        memo[i] = -1;
}

int Fibonacci(int n)
{
    if (memo[n] != -1)
        return memo[n];

    if (n <= 2)
        memo[n] = 1;
    else
        memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);

    return memo[n];
}

int main() {
    cin >> N;

    /*
    fibo[1] = 1;
    fibo[2] = 1;

    for (int i = 3; i <= N; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[N];
    */

    InitMemo();

    cout << Fibonacci(N);    

    return 0;
}

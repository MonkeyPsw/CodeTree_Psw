#include <iostream>

using namespace std;

int N;
int fibo[46];

int main() {
    cin >> N;

    fibo[1] = 1;
    fibo[2] = 1;

    for (int i = 3; i <= N; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[N];

    return 0;
}

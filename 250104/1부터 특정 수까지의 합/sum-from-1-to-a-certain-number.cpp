#include <iostream>

using namespace std;

int N;

int DivideTen(int a)
{
    int sum = 0;
    for (int i = 1; i <= a; i++)
        sum += i;
    return sum / 10;
}

int main() {
    int result;
    cin >> N;

    result = DivideTen(N);
    cout << result;

    return 0;
}
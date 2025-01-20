#include <iostream>

using namespace std;

int N;

int NumberSum(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return n + NumberSum(n - 2);
}

int main() {
    cin >> N;

    cout << NumberSum(N);
    
    return 0;
}
#include <iostream>

using namespace std;

int N;

int Sum(int n)
{
    if (n == 1)
        return 1;
    
    return Sum(n - 1) + n;
}

int main() {
    cin >> N;

    cout << Sum(N);

    return 0;
}
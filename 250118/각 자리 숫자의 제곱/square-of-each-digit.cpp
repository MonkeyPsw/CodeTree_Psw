#include <iostream>

using namespace std;

int N;

int PowerSum(int n)
{
    if (n < 10)
        return n * n;
    
    int num = n % 10;
    
    return PowerSum(n / 10) + num * num;
}

int main() {
    cin >> N;

    cout << PowerSum(N);

    return 0;
}
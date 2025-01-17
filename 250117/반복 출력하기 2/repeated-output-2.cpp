#include <iostream>

using namespace std;

int N;

void PrintHello(int n)
{
    if (n == 0)
        return;
    
    PrintHello(n - 1);
    cout << "HelloWorld" << endl;
}

int main() {
    cin >> N;

    PrintHello(N);

    return 0;
}
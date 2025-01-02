#include <iostream>

using namespace std;

int N;

void PrintLine(int n)
{
    for (int i = 0; i < n; i++)
        cout << "12345^&*()_" << endl;
}

int main() {
    cin >> N;

    PrintLine(N);

    return 0;
}
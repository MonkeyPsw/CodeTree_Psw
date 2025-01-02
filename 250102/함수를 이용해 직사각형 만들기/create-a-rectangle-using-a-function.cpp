#include <iostream>

using namespace std;

int n, m;

void PrintRect(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << 1;
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    PrintRect(n, m);

    return 0;
}
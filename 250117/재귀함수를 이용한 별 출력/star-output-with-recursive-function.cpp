#include <iostream>

using namespace std;

int n;

void PrintStar(int x)
{
    if (x == 0)
        return;

    PrintStar(x - 1);
    for (int i = 0; i < x; i++)
        cout << "*";
    cout << endl;
}

int main() {
    cin >> n;

    PrintStar(n);

    return 0;
}
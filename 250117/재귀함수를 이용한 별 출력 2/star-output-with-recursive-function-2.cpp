#include <iostream>

using namespace std;

int n;

void PrintStar(int x)
{
    if (x == 0)
        return;

    /* 생각해보면 이거도 상관없잖아
    for (int i = 0; i < x; i++)
        cout << "* ";
    */
    for (int i = x; i > 0; i--)
        cout << "* ";
    cout << endl;
    
    PrintStar(x - 1);

    for (int i = 0; i < x; i++)
        cout << "* ";
    cout << endl;
}

int main() {
    cin >> n;

    PrintStar(n);

    return 0;
}
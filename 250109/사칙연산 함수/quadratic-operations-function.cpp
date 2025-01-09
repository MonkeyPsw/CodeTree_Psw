#include <iostream>

using namespace std;

int a;
int c;
char o;

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int main() {
    cin >> a >> o >> c;

    switch (o)
    {
        case '+' :
            cout << a << " + " << c << " = " << Add(a, c);
            break;
        case '-' :
            cout << a << " - " << c << " = " << Sub(a, c);
            break;
        case '*' :
            cout << a << " * " << c << " = " << Mul(a, c);
            break;
        case '/' :
            cout << a << " / " << c << " = " << Div(a, c);
            break;
        default :
            cout << "False";
            break;
    }

    return 0;
}
#include <iostream>

using namespace std;

int n, m;

void GetLCM(int a, int b)
{
    int gcd;
    if (a >= b)
    {
        for (int i = 1; i <= b; i++)
        {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
    }
    else
    {
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
    }

    int lcm = a * b / gcd;
    
    cout << lcm;
}

int main() {
    cin >> n >> m;

    GetLCM(n, m);

    return 0;
}
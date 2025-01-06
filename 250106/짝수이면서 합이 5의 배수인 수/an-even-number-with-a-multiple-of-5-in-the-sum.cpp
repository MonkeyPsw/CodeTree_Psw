#include <iostream>

using namespace std;

int n;

bool IsMagicNum(int a)
{
    int sum = 0;
    sum += (a / 10) + (a % 10);
    return a % 2 == 0 && sum % 5 == 0;
}

int main() {
    cin >> n;
    
    cout << (IsMagicNum(n) ? "Yes" : "No");

    return 0;
}
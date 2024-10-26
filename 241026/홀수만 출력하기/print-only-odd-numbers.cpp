#include <iostream>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2 != 0 && num % 3 == 0)
            cout << num << endl;
    }
    return 0;
}
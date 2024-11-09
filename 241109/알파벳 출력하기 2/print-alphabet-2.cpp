#include <iostream>
using namespace std;

int main() {
    int n;
    char cnt = 'A';
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "  ";
        for (int j = 0; j < n - i; j++)
        {
            if (cnt > 'Z') cnt = 'A';
            cout << cnt++ << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n, a, b;

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        cin >> a >> b;
        
        for (int j = a; j <= b; j++)
            prod *= j;
        cout << prod << endl;
    }

    return 0;
}
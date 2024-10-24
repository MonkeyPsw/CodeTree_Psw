#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 5; i++)
        cout << i * n << " ";
    
    /*
    for(int i = n; i <= 5 * n; i += n)
		cout << i << " ";
    */
    return 0;
}
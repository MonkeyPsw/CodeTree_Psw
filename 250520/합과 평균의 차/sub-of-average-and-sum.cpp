#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    int sum = a + b + c;
    int avg = sum / 3;

    cout << sum << endl;
    cout << avg << endl;
    cout << sum - avg;
    
    return 0;
}
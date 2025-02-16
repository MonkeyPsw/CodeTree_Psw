#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    int start = a * 60 + b;
    int end = c * 60 + d;

    cout << end - start;

    return 0;
}
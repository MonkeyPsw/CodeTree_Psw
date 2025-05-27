#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b;
    cin >> c >> d;

    if (max(a, c) <= min(b, d))
        cout << (max(b, d) - min(a, c));
    else
        cout << (b - a) + (d - c);

    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;

    int length1 = abs(a - b);
    int length2 = abs(a - x) + abs(b - y);
    int length3 = abs(a - y) + abs(b - x);

    cout << min({length1, length2, length3});

    return 0;
}
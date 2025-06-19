#include <iostream>
#include <algorithm>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    int width = max(x2, a2) - min(x1, a1);
    int height = max(y2, b2) - min(y1, b1);

    cout << max(width, height) * max(width, height);

    return 0;
}
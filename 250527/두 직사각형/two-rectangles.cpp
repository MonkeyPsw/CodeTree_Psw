#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

bool IsOverlap(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2)
{
    if (x2 < a1 || a2 < x1 || b2 < y1 || y2 < b1)
        return false;

    return true;
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    if (IsOverlap(x1, y1, x2, y2, a1, b1, a2, b2))
        cout << "overlapping";
    else
        cout << "nonoverlapping";

    return 0;
}
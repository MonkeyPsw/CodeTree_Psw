#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;
int rect[11][11];

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    int minX, maxX;
    int minY, maxY;

    if (x1 <= a1)
        minX = x1;
    else
        minX = a1;

    if (x2 >= a2)
        maxX = x2;
    else
        maxX = a2;

    if (y1 <= b1)
        minY = y1;
    else
        minY = b1;
        
    if (y2 >= b2)
        maxY = y2;
    else
        maxY = b2;

    for (int i = minX; i < maxX; i++)
    {
        for (int j = minY; j < maxY; j++)
            rect[i][j] = 1;
    }

    int total = 0;
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
            total += rect[i][j];
    }

    cout << total;

    return 0;
}
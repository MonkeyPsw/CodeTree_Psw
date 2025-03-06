#include <iostream>

#define OFFSET 1000

using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];
int rect[2001][2001];

int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    for (int i = 0; i < 2; i++)
    {
        x1[i] += OFFSET;
        y1[i] += OFFSET;
        x2[i] += OFFSET;
        y2[i] += OFFSET;

        for (int j = x1[i]; j < x2[i]; j++)
        {
            for (int k = y1[i]; k < y2[i]; k++)
                rect[j][k] = 1 - i;
        }
    }

    int minX = 2001, minY = 2001;
    int maxX = -1, maxY = -1;

    for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= 2000; j++)
        {
            if (rect[i][j] == 1)
            {    
                minX = min(minX, i);
                maxX = max(maxX, i);
                minY = min(minY, j);
                maxY = max(maxY, j);
            }
        }
    }

    int total = 0;
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
            total++;
    }
    
    if (maxX == -1 || maxY == -1)
        total = 0;

    cout << total;

    return 0;
}
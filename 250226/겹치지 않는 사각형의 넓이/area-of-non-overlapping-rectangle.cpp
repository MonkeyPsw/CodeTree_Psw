#include <iostream>

using namespace std;

#define OFFSET 1000

int x1[3], ya1[3];
int x2[3], ya2[3];
int rect[2001][2001];

void PaintRect(int target[2001][2001], int arr1[], int arr2[], int arr3[], int arr4[], int n, int idx)
{
    for (int i = arr1[n]; i < arr2[n]; i++)
    {
        for (int j = arr3[n]; j < arr4[n]; j++)
                target[i][j] = idx;
    }
}

int main() {
    cin >> x1[0] >> ya1[0] >> x2[0] >> ya2[0];
    cin >> x1[1] >> ya1[1] >> x2[1] >> ya2[1];
    cin >> x1[2] >> ya1[2] >> x2[2] >> ya2[2];
    
    for (int i = 0; i < 3; i++)
    {
        x1[i] += OFFSET;
        ya1[i] += OFFSET;
        x2[i] += OFFSET;
        ya2[i] += OFFSET;
    }

    // 나 왜 전체 넓이를 구하려 하고있니
    PaintRect(rect, x1, x2, ya1, ya2, 0, 1);
    PaintRect(rect, x1, x2, ya1, ya2, 1, 2);
    PaintRect(rect, x1, x2, ya1, ya2, 2, 0);

    /* 나 뭐하냐 정신이 없네
    int minX = -1, minY = -1;
    int maxX = -1, maxY = -1;

    for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= 2000; j++)
        {
            
            if (minX > rect[i][j])
                minX = rect[i][j];
            if (maxX < rect[i][j])
                maxX = rect[i][j];
            if (minY > rect[i][j])
                minY = rect[i][j];
            if (maxY < rect[i][j])
                maxY = rect[i][j];
        }
    }

    int total = 0;
    for (int i = minX; i < maxX; i++)
    {
        for (int j = minY; j < maxY; j++)
        {
            if (!rect[i][j])
                total++;
        }
    }
    */

    int total = 0;
    for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= 2000; j++)
        {
            if (rect[i][j])
                total++;
        }
    }

    cout << total;

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[20], y[20];
int sortX[20], sortY[20];
int valX[11], valY[11];
int line[22][2];
int cnt, cntX, cntY;

void sortAndEraseDupVal()
{
    sort(sortX, sortX + n);
    sort(sortY, sortY + n);

    valX[cntX++] = sortX[0];
    valY[cntY++] = sortY[0];

    for (int i = 1; i < n; i++)
    {
        if (sortX[i] != valX[cntX - 1])
            valX[cntX++] = sortX[i];

        if (sortY[i] != valY[cntY - 1])
            valY[cntY++] = sortY[i];
    }
}

void valToLine()
{
    for (int i = 0; i < cntX; i++)
    {
        line[cnt][0] = 0;
        line[cnt][1] = valX[i];
        cnt++;
    }

    for (int i = 0; i < cntY; i++)
    {
        line[cnt][0] = 1;
        line[cnt][1] = valY[i];
        cnt++;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    copy(x, x + n, sortX);
    copy(y, y + n, sortY);

    sortAndEraseDupVal();
    valToLine();

    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            for (int k = j + 1; k < cnt; k++)
            {
                bool isRight = true;
                bool point[20] = {false};

                for (int l = 0; l < n; l++)
                {
                    if ((line[i][0] == 0 && line[i][1] == x[l]) ||
                        (line[i][0] == 1 && line[i][1] == y[l]) ||
                        (line[j][0] == 0 && line[j][1] == x[l]) ||
                        (line[j][0] == 1 && line[j][1] == y[l]) ||
                        (line[k][0] == 0 && line[k][1] == x[l]) ||
                        (line[k][0] == 1 && line[k][1] == y[l]))
                        point[l] = true;
                }

                for (int l = 0; l < n; l++)
                {
                    if (!point[l])
                    {
                        isRight = false;
                        break;
                    }
                }
                
                if (isRight)
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;

    return 0;
}
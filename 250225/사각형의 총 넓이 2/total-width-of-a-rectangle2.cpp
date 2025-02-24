#include <iostream>

using namespace std;

#define OFFSET 100

int N;
int x1[10], y1[10];
int x2[10], y2[10];
int rect[201][201];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        x1[i] += OFFSET;
        y1[i] += OFFSET;
        x2[i] += OFFSET;
        y2[i] += OFFSET;

        for (int j = x1[i]; j < x2[i]; j++)
        {
            for (int k = y1[i]; k < y2[i]; k++)
                rect[j][k] = 1;
        }
    }

    int total = 0;
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= 200; j++)
            total += rect[i][j];
    }

    cout << total;

    return 0;
}
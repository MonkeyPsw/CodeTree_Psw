#include <iostream>

#define OFFSET 100

using namespace std;

int N;
int x[100], y[100];
int rect[201][201];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];

        x[i] += OFFSET;
        y[i] += OFFSET;

        for (int j = x[i]; j < x[i] + 8; j++)
        {
            for (int k = y[i]; k < y[i] + 8; k++)
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
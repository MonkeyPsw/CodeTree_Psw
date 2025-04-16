#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int x[100];
int y[100];
double ans = 0;

int CalTriX(int a, int b, int c)
{
    if (x[a] == x[b])
        return abs(x[c] - x[a]);
    else if (x[a] == x[c])
        return abs(x[b] - x[a]);
    else if (x[b] == x[c])
        return abs(x[a] - x[b]);
}

int CalTriY(int a, int b, int c)
{
    if (y[a] == y[b])
        return abs(y[c] - y[a]);
    else if (y[a] == y[c])
        return abs(y[b] - y[a]);
    else if (y[b] == y[c])
        return abs(y[a] - y[b]);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // y가 같으면 x축 평행, x가 같으면 y축 평행
    // 2개만 같아야 한다? 
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (x[i] != x[j] && x[i] != x[k] && x[j] != x[k] ||
                    y[i] != y[j] && y[i] != y[k] && y[j] != y[k])
                    continue;
                
                int valX = CalTriX(i, j, k);
                int valY = CalTriY(i, j, k);
                double tmp = valX * valY * 0.5;

                ans = max(ans, tmp);
            }
        }
    }

    cout << ans * 2;

    return 0;
}
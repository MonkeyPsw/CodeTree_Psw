#include <iostream>
#include <cmath>

using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;
int cnt;

bool InRange(int abc, int num)
{
    return (abs(abc - num) <= 2 || abs(abc - num) >= N - 2);
}

int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (InRange(a1, i) && InRange(b1, j) && InRange(c1, k) ||
                    InRange(a2, i) && InRange(b2, j) && InRange(c2, k))
                    cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
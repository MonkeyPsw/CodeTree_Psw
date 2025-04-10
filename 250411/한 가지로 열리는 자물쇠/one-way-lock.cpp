#include <iostream>
#include <cmath>

using namespace std;

int N;
int a, b, c;
int cnt;

int main() {
    cin >> N;
    cin >> a >> b >> c;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (abs(i - a) <= 2 || abs(j - b) <= 2 || abs(k - c) <= 2)
                    cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
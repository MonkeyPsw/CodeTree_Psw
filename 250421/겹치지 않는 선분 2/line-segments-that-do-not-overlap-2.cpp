#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x1[100], x2[100];
int cnt;

bool IsCross(int x1, int x2, int y1, int y2)
{
    if (x1 > y1)
        return (x2 < y2);
    else
        return (x2 > y2);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < N; i++)
    {
        bool isAlone = true;

        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            
            if (IsCross(x1[i], x2[i], x1[j], x2[j]))
            {
                isAlone = false;
                break;
            }
        }

        if (isAlone)
            cnt++;
    }

    cout << cnt;

    return 0;
}
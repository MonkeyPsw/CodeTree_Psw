#include <iostream>

using namespace std;

int N;
int numbers[1000];
int odd, even;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (numbers[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    int ans = N;

    while (ans > 0)
    {
        bool isBundle = false;
        int curOddCnt = odd;
        int curEvenCnt = even;
        int targetOddCnt = ans / 2;
        int targetEvenCnt = ans - targetOddCnt;

        int remainOddCnt = curOddCnt - targetOddCnt;

        if (remainOddCnt >= 0)
        {
            if ((remainOddCnt) % 2 == 0)
            {
                int remainEvenCnt = targetEvenCnt - curEvenCnt;

                if (remainEvenCnt <= remainOddCnt / 2)
                    isBundle = true;
            }
        }

        if (isBundle)
            break;
        else
            ans--;
    }

    cout << ans;

    return 0;
}
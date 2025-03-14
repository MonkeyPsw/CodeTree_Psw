#include <iostream>
#include <algorithm>

using namespace std;

int N, K, P, T;
int t[250];
int x[250];
int y[250];
int inf[101]; // 감염 여부 배열 : 0, 1
int cnt[101]; // 감염 횟수 배열 : 0 ~ K

class HandShake {
    public :
        int t, x, y;

        HandShake(int t, int x, int y) {
            this->t = t;
            this->x = x;
            this->y = y;
        }

        HandShake() {}
};

bool cmpTime(HandShake a, HandShake b)
{
    return a.t < b.t;
}

int main() {
    HandShake h[250];

    cin >> N >> K >> P >> T;

    for (int i = 0; i < T; i++) {
        cin >> t[i] >> x[i] >> y[i];

        h[i] = HandShake(t[i], x[i], y[i]);
    }

    sort(h, h + T, cmpTime);

    inf[P] = 1;

    for (int i = 0; i < T; i++)
    {
        if (inf[h[i].x])
        {
            if (inf[h[i].y])
            {
                cnt[h[i].x]++;
                cnt[h[i].y]++;
            }
            else
            {
                if (cnt[h[i].x] < K)
                {
                    cnt[h[i].x]++;
                    inf[h[i].y] = 1;
                }
            }
        }
        else if (inf[h[i].y])
        {
            if (inf[h[i].x])
            {
                cnt[h[i].x]++;
                cnt[h[i].y]++;
            }
            else
            {
                if (cnt[h[i].y] < K)
                {
                    cnt[h[i].y]++;
                    inf[h[i].x] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << inf[i];

    return 0;
}
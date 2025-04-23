#include <iostream>
#include <algorithm>

using namespace std;

int N, B;
int P[1000];
int S[1000];
int ans;

/* 너무 어렵게 풀었어
class Gift {
    public :
        int price, ship, index;

        Gift(int p, int s, int i) {
            price = p;
            ship = s;
            index = i;
        }

        Gift() {}
};

bool CmpPrice(Gift a, Gift b)
{
    return a.price + a.ship < b.price + b.ship;
}

int main() {
    Gift g[1000];

    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i] >> S[i];

        g[i] = Gift(P[i], S[i], i);
    }

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            if (g[j].index == i)
            {
                g[j].price /= 2;
                break;
            }
        }
        
        sort(g, g + N, CmpPrice);

        for (int j = 0; j < N; j++)
        {
            sum += g[j].price + g[j].ship;

            if (sum > B)
                break;

            cnt++;
        }

        ans = max(ans, cnt);

        for (int j = 0; j < N; j++)
        {
            if (g[j].index == i)
            {
                g[j].price *= 2;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
*/

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i] >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int cnt = 0;
        int arr[1000] = {};

        P[i] /= 2;

        for (int j = 0; j < N; j++)
            arr[j] = P[j] + S[j];

        sort(arr, arr + N);

        for (int j = 0; j < N; j++)
        {
            sum += arr[j];

            if (sum > B)
                break;

            cnt++;
        }

        ans = max(ans, cnt);

        P[i] *= 2;
    }

    cout << ans;

    return 0;
}
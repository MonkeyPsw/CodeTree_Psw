#include <iostream>
#include <algorithm>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];
int ans;

int GetTemp(int n, int i)
{
    if (Ta[n] > i)
        return C;
    else if (Ta[n] <= i && Tb[n] >= i)
        return G;
    else
        return H;
}

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
    }

    for (int i = 0; i <= 1000; i++)
    {
        int sum = 0;

        for (int j = 0; j < N; j++)
            sum += GetTemp(j, i);

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
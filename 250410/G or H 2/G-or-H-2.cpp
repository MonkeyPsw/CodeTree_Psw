#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int pos[100];
char alpha[100];
char line[101];
int ans = INT_MIN;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pos[i] >> alpha[i];

        line[pos[i]] = alpha[i];
    }

    for (int i = 0; i <= 100; i++)
    {
        for (int j = i; j <= 100; j++)
        {
            int cntG = 0;
            int cntH = 0;

            for (int k = i; k <= j; k++)
            {
                if (line[k] == 'G')
                    cntG++;
                if (line[k] == 'H')
                    cntH++;
            }

            if ((cntG && !cntH) ||
                (!cntG && cntH) ||
                (cntG == cntH && cntG > 0))
            {
                if (line[i] != '\0' && line[j] != '\0')
                    ans = max(ans, j - i);
            }
        }
    }

    cout << ans;

    return 0;
}
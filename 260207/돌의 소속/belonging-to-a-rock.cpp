#include <iostream>

using namespace std;

int N, Q;
int preSum[4][100001];

int main() {
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;

        for (int j = 1; j <= 3; j++)
            preSum[j][i] = preSum[j][i - 1];
        
        preSum[x][i]++;
    }

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = 1; j <= 3; j++)
            cout << preSum[j][b] - preSum[j][a - 1] << " ";
        cout << endl;
    }

    return 0;
}

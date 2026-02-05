#include <iostream>

using namespace std;

int N, Q;
int points[1000001];
int A[100000], B[100000];
int preSum[1000001];

int main() {
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        points[x]++;
    }

    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 1; i <= 1000000; i++)
        preSum[i] = preSum[i - 1] + points[i];

    for (int i = 0; i < Q; i++)
    {
        if (A[i] == 0)
            cout << preSum[B[i]] << endl;
        else
            cout << preSum[B[i]] - preSum[A[i] - 1] << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int N, K;
int A[100], B[100];
int Box[101];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];

        for (int j = A[i]; j <= B[i]; j++)
            Box[j]++;
    }

    int max = Box[1];
    for (int i = 1; i <= N; i++)
    {
        if (max < Box[i])
            max = Box[i];
    }

    cout << max;

    return 0;
}
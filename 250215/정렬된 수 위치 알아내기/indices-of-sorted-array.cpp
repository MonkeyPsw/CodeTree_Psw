#include <iostream>
#include <algorithm>

using namespace std;

int N;
int sequence[1000];
int seq_to_rank[1001];

class Number {
    public :
        int n, index;

        Number(int input, int i) {
            n = input;
            index = i;
        }

        Number() {}
};

bool cmp(Number a, Number b)
{
    if (a.n == b.n)
        return a.index < b.index;
    return a.n < b.n;
}

int main() {
    Number n[1000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];

        n[i] = Number(sequence[i], i + 1);
    }

    sort(n, n + N, cmp);

    for (int i = 1; i <= N; i++)
        seq_to_rank[n[i].index] = i;

    for (int i = 1; i <= N; i++)
        cout << seq_to_rank[i] + 1 << " ";

    return 0;
}

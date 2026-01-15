#include <iostream>
#include <unordered_set>

using namespace std;

int N, K;
int a[100000], b[100000];
unordered_set<int> ust[100001];
int seat[100001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= N; i++)
    {
        seat[i] = i;
        ust[i].insert(i);
    }

    for (int t = 0; t < 3; t++)
    {
        for (int i = 0; i < K; i++)
        {
            swap(seat[a[i]], seat[b[i]]);

            ust[seat[a[i]]].insert(b[i]);
            ust[seat[b[i]]].insert(a[i]);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ust[i].size() << endl;

    return 0;
}

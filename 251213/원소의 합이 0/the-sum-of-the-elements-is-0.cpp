#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];
unordered_map<long long, long long> ump;
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    for (int i = 0; i < n; i++) cin >> C[i];

    for (int i = 0; i < n; i++) cin >> D[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ump[A[i] + B[j]]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = C[i] + D[j];

            if (ump.find(-tmp) != ump.end())
                ans += ump[-tmp];
        }
    }
    
    cout << ans;

    return 0;
}

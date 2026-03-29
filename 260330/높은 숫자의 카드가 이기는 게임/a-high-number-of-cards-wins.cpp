#include <iostream>
#include <set>

using namespace std;

int N;
int B[50000];
set<int> A;
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= N * 2; i++)
        A.insert(i);
    
    for (int i = 0; i < N; i++)
        A.erase(B[i]);

    for (int i = 0; i < N; i++)
    {
        if (A.upper_bound(B[i]) != A.end())
        {
            ans++;
            A.erase(A.upper_bound(B[i]));
        }
        else
            A.erase(A.begin());
    }

    cout << ans;

    return 0;
}

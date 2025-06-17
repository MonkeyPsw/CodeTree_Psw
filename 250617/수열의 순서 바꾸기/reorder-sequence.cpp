#include <iostream>

using namespace std;

int N;
int sequence[100];
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    for (int i = N - 1; i >= 1; i--)
    {
        if (sequence[i] < sequence[i - 1])
        {
            ans = i;
            break;
        }
    }
    
    cout << ans;

    return 0;
}
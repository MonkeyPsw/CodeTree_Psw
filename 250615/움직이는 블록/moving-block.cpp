#include <iostream>

using namespace std;

int n;
int blocks[10000];
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += blocks[i];
    
    int cnt = sum / n;
    for (int i = 0; i < n; i++)
    {
        if (blocks[i] > cnt)
            ans += blocks[i] - cnt;
    }

    cout << ans;

    return 0;
}
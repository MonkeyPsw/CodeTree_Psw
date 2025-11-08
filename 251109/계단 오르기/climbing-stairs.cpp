#include <iostream>

using namespace std;

int n;
int stair[1001];

int main() {
    cin >> n;
    
    stair[2] = 1;
    stair[3] = 1;

    for (int i = 4; i <= n; i++)
        stair[i] = (stair[i - 2] + stair[i - 3]) % 10007;

    cout << stair[n];

    return 0;
}
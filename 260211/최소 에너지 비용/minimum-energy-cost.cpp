#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dist[100000];
int cost[100000];
int bestCost[100000];
long long ans;

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> dist[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    bestCost[0] = cost[0];
    for (int i = 1; i < n; i++)
        bestCost[i] = min(bestCost[i - 1], cost[i]);
    
    for (int i = 0; i < n - 1; i++)
        ans += (long long)bestCost[i] * dist[i];

    cout << ans;

    return 0;
}

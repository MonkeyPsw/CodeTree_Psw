#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
string words[100000];
int ans;
unordered_map<string, int> strToIdx;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        strToIdx[words[i]]++;
    }

    for (int i = 0; i < n; i++)
        ans = max(ans, strToIdx[words[i]]);
        
    cout << ans;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
string words[1000];
unordered_map<string, int> sMap;
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];

        sort(words[i].begin(), words[i].end());

        sMap[words[i]]++;
    }

    /*
    for (int i = 0; i < n; i++)
        ans = max(ans, sMap[words[i]]);
    */

    unordered_map<string, int>::iterator it;
    for (it = sMap.begin(); it != sMap.end(); it++)
        ans = max(ans, it->second);

    cout << ans;

    return 0;
}

#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words[10000];
map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];

        mp[words[i]]++;
    }

    cout << fixed;
    cout.precision(4);

    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second * 100 / (float)n << endl;

    return 0;
}

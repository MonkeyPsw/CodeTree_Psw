#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

int n, m;
string words[100000];
string queries[100000];

unordered_map<string, int> sMap;
unordered_map<int, string> iMap;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];

        sMap[words[i]] = i;
        iMap[i] = words[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];

        if (isdigit(queries[i][0]))
            cout << iMap[stoi(queries[i])];
        else
            cout << sMap[queries[i]];

        cout << endl;
    }

    return 0;
}

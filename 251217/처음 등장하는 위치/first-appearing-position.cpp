#include <iostream>
#include <map>

using namespace std;

int n;
int arr[100000];
map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (mp.find(arr[i]) == mp.end())
            mp[arr[i]] = i + 1;
    }

    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}

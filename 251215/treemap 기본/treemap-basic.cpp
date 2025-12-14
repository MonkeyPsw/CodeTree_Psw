#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];
map<int, int> mp;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "add") {
            cin >> k[i] >> v[i];
        } else if (cmd[i] == "remove" || cmd[i] == "find") {
            cin >> k[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cmd[i] == "add")
            mp[k[i]] = v[i];
        else if (cmd[i] == "remove")
            mp.erase(k[i]);
        else if (cmd[i] == "find")
        {
            if (mp.find(k[i]) != mp.end())
                cout << mp[k[i]];
            else
                cout << "None";
            
            cout << endl;
        }
        else
        {
            if (mp.empty())
                cout << "None";
            else
            {
                map<int, int>::iterator it;
                
                for (it = mp.begin(); it != mp.end(); it++)
                    cout << it->second << " ";
            }

            cout << endl;
        }
    }

    return 0;
}

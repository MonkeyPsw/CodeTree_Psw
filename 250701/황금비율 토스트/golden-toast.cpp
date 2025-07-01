#include <iostream>
#include <string>
#include <list>

using namespace std;

int n, m;
string s;
list<char> l;
list<char>::iterator it;

int main() {
    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < n; i++)
        l.push_back(s[i]);
    
    it = l.end();

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        if (command == 'L')
        {
            if (it != l.begin())
                it--;
        }
        else if (command == 'R')
        {
            if (it != l.end())
                it++;
        }
        else if (command == 'D')
        {
            if (it != l.end())
                l.erase(it);
        }
        else if (command == 'P')
        {
            char c;
            cin >> c;

            l.insert(it, c);
        }
    }

    for (it = l.begin(); it != l.end(); it++)
        cout << *it;

    return 0;
}

#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

int n, m;
int P[100001], L[100001];
set<pair<int, int> > pst;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i] >> L[i];

        pst.insert(make_pair(L[i], P[i]));
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string command;
        cin >> command;

        if (command == "rc")
        {
            set<pair<int, int> >::iterator it;
            int x;
            cin >> x;

            if (x == 1)
            {
                it = pst.end();
                it--;
                cout << it->second;
            }
            else
            {
                it = pst.begin();
                cout << it->second;
            }

            cout << endl;
        }
        else if (command == "ad")
        {
            int p, l;
            cin >> p >> l;

            pst.insert(make_pair(l, p));
        }
        else if (command == "sv")
        {
            int p, l;
            cin >> p >> l;

            pst.erase(make_pair(l, p));
        }
    }

    return 0;
}
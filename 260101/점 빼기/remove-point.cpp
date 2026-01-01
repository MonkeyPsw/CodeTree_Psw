#include <iostream>
#include <set>
#include <utility>

using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];
int k[MAX_N];
set<pair<int, int> > pst;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        pst.insert(make_pair(x[i], y[i]));
    }

    for (int i = 0; i < m; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < m; i++)
    {
        set<pair<int, int> >::iterator it = pst.lower_bound(make_pair(k[i], -1));

        if (it == pst.end())
            cout << -1 << " " << -1;
        else
        {
            cout << it->first << " " << it->second;
            pst.erase(it);
        }
    
        cout << endl;
    }

    return 0;
}
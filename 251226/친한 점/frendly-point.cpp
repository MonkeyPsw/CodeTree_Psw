#include <iostream>
#include <set>
#include <utility>

using namespace std;

int n, m;
int x[100000], y[100000];
int qx[100000], qy[100000];
set<pair<int, int> > pst;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        pst.insert(make_pair(x[i], y[i]));
    }

    for (int i = 0; i < m; i++) cin >> qx[i] >> qy[i];

    for (int i = 0; i < m; i++)
    {
        set<pair<int, int> >::iterator it = pst.lower_bound(make_pair(qx[i], qy[i]));

        if (it == pst.end())
            cout << -1 << " " << -1;
        else
            cout << it->first << " " << it->second;

        cout << endl;
    }

    return 0;
}

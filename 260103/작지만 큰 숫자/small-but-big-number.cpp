#include <iostream>
#include <set>

using namespace std;

int n, m;
int sequence[100000];
int query[100000];
set<int> st;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];

        st.insert(sequence[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i];
    }

    for (int i = 0; i < m; i++)
    {
        set<int>::iterator it = st.upper_bound(query[i]);

        if (it != st.begin())
        {
            cout << *--it << endl;
            st.erase(it);
        }
        else
        {
            cout << -1 << endl;
            continue;
        }
    }

    return 0;
}

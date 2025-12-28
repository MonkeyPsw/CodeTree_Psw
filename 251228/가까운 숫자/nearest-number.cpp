#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
int queries[100000];
set<int> st;
int cnt = 100000;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    st.insert(0);

    for (int i = 0; i < n; i++)
    {
        st.insert(queries[i]);

        set<int>::iterator it = st.lower_bound(queries[i]);
        
        if (next(it) == st.end())
            cnt = min(cnt, queries[i] - *prev(it));
        else
        {
            int tmp = min(queries[i] - *prev(it), *next(it) - queries[i]);
            cnt = min(cnt, tmp);
        }

        cout << cnt << endl;
    }

    return 0;
}

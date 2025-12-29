#include <iostream>
#include <set>

using namespace std;

int n, m;
int a[100000];
set<int> st;
int cnt;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
        st.insert(i);
    
    for (int i = 0; i < n; i++)
    {
        set<int>::iterator it = st.upper_bound(a[i]);
        it--;

        if (*it <= a[i])
        {
            st.erase(it);
            cnt++;
        }
        else
            break;
    }

    cout << cnt;

    return 0;
}
